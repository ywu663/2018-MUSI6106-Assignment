// standard headers
#include <limits>
#include <float.h>


// project headers
#include "MUSI6106Config.h"

#include "ErrorDef.h"
#include "Util.h"
#include "RingBuffer.h"

#include "CombFilterIf.h"
#include "CombFilter.h"



//CCombFilterBase class constructor
CCombFilterBase::CCombFilterBase( int iMaxDelayInFrames, int iNumChannels ) :
m_ppCRingBuffer(0),
m_iNumChannels(iNumChannels)
{
    
    assert(iMaxDelayInFrames > 0);
    assert(iNumChannels > 0);
    
    //set up gain parameter range
    //but for IIR we have specific gain range to prevent it from exploding.
    //(please see CCombFilterIir::CCombFilterIir)
    m_aafParamRange[CCombFilterIf::kParamGain][0] = FLT_MIN;
    m_aafParamRange[CCombFilterIf::kParamGain][1] = FLT_MAX;
    //set up delay parameter range
    m_aafParamRange[CCombFilterIf::kParamDelay][0] = 0;
    m_aafParamRange[CCombFilterIf::kParamDelay][1] = static_cast<float>(iMaxDelayInFrames);
    //initialize all the parameters to 0
    for (int i = 0; i < CCombFilterIf::kNumFilterParams; i++)
    {
        m_afParam[i] = 0.F;
    }
    // Ring buffer memory allocation, each CRingBuffer for a channel
    m_ppCRingBuffer = new CRingBuffer<float>* [iNumChannels];
    for (int i = 0; i < iNumChannels; i++)
    {
        m_ppCRingBuffer[i] = new CRingBuffer<float>(iMaxDelayInFrames);
    }
}

//CCombFilterBase class destructor
CCombFilterBase::~CCombFilterBase()
{
    for (int i = 0; i < m_iNumChannels; i++)
    {
        delete m_ppCRingBuffer[i];
    }
    delete [] m_ppCRingBuffer;
}

Error_t CCombFilterBase::resetInstance()
{
    
    for (int i = 0; i < m_iNumChannels; i++)
    {
        m_ppCRingBuffer[i]->reset();
        
        // reset RingBuffer Write from delay length
        m_ppCRingBuffer[i]->setWriteIdx(CUtil::float2int<int>(m_afParam[CCombFilterIf::kParamDelay]));
    }
    return kNoError;
}

Error_t CCombFilterBase::setParam( CCombFilterIf::FilterParam_t eParam, float fParamValue )
{
    //check if parameter argument is out of range
    if (!isInParamRange(eParam, fParamValue))
        return kFunctionInvalidArgsError;
    
    //check if new delay parameter is greater than the current delay parameter
    if (eParam == CCombFilterIf::kParamDelay)
    {
        //if the new delay parameter is greater or equal to the current delay parameter
        //push additional zeros to the ring buffer from the writing index to the back
        if (CUtil::float2int<int>(fParamValue - m_afParam[CCombFilterIf::kParamDelay]) >= 0)
        {
            for (int i = 0; i < m_iNumChannels; i++)
            {
                for (int j = 0; j < CUtil::float2int<int>(fParamValue - m_afParam[CCombFilterIf::kParamDelay]); j++)
                {
                    m_ppCRingBuffer[i]->putPostInc(0.F);
                }
            }
        }
        //if the new delay parameter is less than the current delay parameter
        //set the new write idx to new delay-parameter frames after the read index
        else
        {
            for (int i = 0; i < m_iNumChannels; i++)
            {
                m_ppCRingBuffer[i]->setWriteIdx( m_ppCRingBuffer[i]->getReadIdx() + CUtil::float2int<int>(fParamValue));
            }
        }
    }
    
    //set parameters for the comb filter
    m_afParam[eParam]   = fParamValue;
    return kNoError;
    

}

float CCombFilterBase::getParam( CCombFilterIf::FilterParam_t eParam ) const
{
    return m_afParam[eParam];
}


// check if parameter is out of range
bool CCombFilterBase::isInParamRange( CCombFilterIf::FilterParam_t eParam, float fValue )
{
    if (fValue < m_aafParamRange[eParam][0] || fValue > m_aafParamRange[eParam][1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

//FIR algorithm implementation
Error_t CCombFilterFir::process( float **ppfInputBuffer, float **ppfOutputBuffer, int iNumberOfFrames )
{
    for (int i = 0; i < m_iNumChannels; i++)
    {
        for (int j = 0; j < iNumberOfFrames; j++ )
        {
            //assign InppuBuffer
            m_ppCRingBuffer[i]->putPostInc(ppfInputBuffer[i][j]);
            // y(n)=x(n)+g*Delayline(10);
            ppfOutputBuffer[i][j] = ppfInputBuffer[i][j] + m_afParam[CCombFilterIf::kParamGain] * m_ppCRingBuffer[i]->getPostInc();
        }
        
    }
    
    return kNoError;
    
}

//IIR gain parameter range setup
CCombFilterIir::CCombFilterIir (int iMaxDelayInFrames, int iNumChannels) : CCombFilterBase(iMaxDelayInFrames, iNumChannels)
{
    //For the IIR filter, set a limit to the parameter range to prevent it from exploding.
    m_aafParamRange[CCombFilterIf::kParamGain][0] = -1.F;
    m_aafParamRange[CCombFilterIf::kParamGain][1] = 1.F;
    
}

//IIR algorithm implementation
Error_t CCombFilterIir::process( float **ppfInputBuffer, float **ppfOutputBuffer, int iNumberOfFrames )
{
    for (int i = 0; i < m_iNumChannels; i++)
    {
        for (int j = 0; j < iNumberOfFrames; j++ )
        {
            
            // y(n)=x(n)+g*Delayline(10);
            ppfOutputBuffer[i][j] = ppfInputBuffer[i][j] + m_afParam[CCombFilterIf::kParamGain] * m_ppCRingBuffer[i]->getPostInc();
            m_ppCRingBuffer[i]->putPostInc(ppfOutputBuffer[i][j]);
        }
        
    }
    return kNoError;
}
