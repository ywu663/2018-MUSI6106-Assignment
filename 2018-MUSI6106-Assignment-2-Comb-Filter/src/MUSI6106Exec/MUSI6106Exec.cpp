
#include <iostream>
#include <ctime>

#include "MUSI6106Config.h"

#include "AudioFileIf.h"
#include "CombFilterIf.h"

using std::cout;
using std::endl;

// local function declarations
void    showClInfo ();

/////////////////////////////////////////////////////////////////////////////////
// main function
int main(int argc, char* argv[])
{
    std::string             sInputFilePath,                 //!< file paths
                            sOutputFilePath;

    static const int        kBlockSize = 1024;
    float                   fMaxDelay = 10;
    int                     defaultSampleRateInHz = 10;
    clock_t                 time = 0;
    
    float                   **ppfAudioData = 0;
    float                   **ppfOutput = 0;
    
    CAudioFileIf            *phAudioFile = 0;
    CAudioFileIf            *phAudioOutFile = 0;
    
    CAudioFileIf::FileSpec_t stFileSpec;
    CCombFilterIf::CombFilterType_t enumFilterType;
    CCombFilterIf   *pInstance = 0;
    CCombFilterIf::create(pInstance);
    showClInfo();
    
    //test signal
    float                   **pfTestSignal       = 0;
    static const int        iTestSignalLength = 30;
    static const int        iTestNumChannels = 2;
    //set initial parameter value
    float                   fGain = 0, fDelay = 0, fTestGain = 0.5, fTestDelay = 1;
    int                     iFilterType = 0;
    int                     iFIR = 0, iIIR = 1;
    

//////////////////////////////////////////////////////////////////////////////
// parse command line arguments
    
    cout << "Enter 1.Filepath 2.FilterType 3.Gain 4.Delay "<< endl;
    cout << "---------------------------------------------------------------------------------"<< endl;
    if (argc < 3)
    {
        cout << "Missing audio input or output path! Running with test signal only"<< endl;
    }
    else if (argc == 3)
    {
        cout << "Missing parameters: Using default Filter = FIR Filter, Gain = 0, Delay = 0. Running all test cases"<< endl;
        sInputFilePath = argv[1];
        sOutputFilePath = argv[2];
        
    }
    else if (argc == 4)
    {
        cout << "Missing parameters: Using default Gain = 0, Delay = 0. Running all test cases"<< endl;
        sInputFilePath = argv[1];
        sOutputFilePath = argv[2];
        iFilterType = atoi(argv[3]);
        
        
    }
    else if (argc == 5)
    {
        cout << "Missing parameters: Using default Delay = 0. Running all test cases"<< endl;
        sInputFilePath = argv[1];
        sOutputFilePath = argv[2];
        iFilterType = atoi(argv[3]);
        fGain = atof(argv[4]);
        
        
    }
    else
    {
        cout << "All parameter assigned. Running all test cases"<< endl;
        sInputFilePath = argv[1];
        sOutputFilePath = argv[2];
        iFilterType = atoi(argv[3]);
        fGain = atof(argv[4]);
        fDelay= atof(argv[5]);
    }

//////////////////////////////////////////////////////////////////////////////
// allocate memory for test cases
    
    pfTestSignal = new float*[iTestNumChannels];
    ppfOutput =  new float*[iTestNumChannels];
    for (int i = 0; i < iTestNumChannels; i++)
    {
        pfTestSignal[i] = new float[kBlockSize];
        ppfOutput[i] = new float[kBlockSize];
    }
    
    time = clock();
    
//////////////////////////////////////////////////////////////////////////////
// fill the test signal (a unit impulse, with 100 Frames)
    for (int i = 0; i < iTestNumChannels;  i++)
    {
        for (int j = 0; j < kBlockSize; j++)
        {
            pfTestSignal[i][j] = 0;
        }
    }
    pfTestSignal[0][0] = 1;
    pfTestSignal[1][0] = 1;
    
//test case1: using test signal, without any parameters (default)
    cout << "---------------------------------------------------------------------------------"<< endl;
    cout << "Test case 1: using unit impulse as test signal, without any parameter" << endl;
    cout << " Testing FIR:" << endl;
    //Switch between FilterType
    switch (iFIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->reset();
    pInstance->init(enumFilterType, fMaxDelay, defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"<< endl;
    
    cout << " Testing IIR:" << endl;
    //Switch between FilterType
    switch (iIIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->reset();
    pInstance->init(enumFilterType, fMaxDelay,defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0.25,0,0,0,0,0,0,0,0,0"<< endl;
    
    
//test case2: using test signal, with gain >=1
    cout << "---------------------------------------------------------------------------------"<< endl;
    cout << "Test case 2: using unit impulse as test signal, with gain >= 1" << endl;
    fTestGain = 2;
    cout << " Testing FIR (we allow gain >=1 in FIR):" << endl;
    //Switch between FilterType
    switch (iFIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->reset();
    pInstance->init(enumFilterType, fMaxDelay,defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"<< endl;
    
    cout << " Testing IIR (gain >=1 not allowed in IIR):" << endl;
    //Switch between FilterType
    
    pInstance->reset();
    switch (iIIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->init(enumFilterType, fMaxDelay,defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"<< endl;
    
    
    
//test case3: using test signal, with delay >=1
    cout << "---------------------------------------------------------------------------------"<< endl;
    cout << "Test case 3: using unit impulse as test signal, with negative Delay" << endl;
    fTestGain  = 0.5;
    fTestDelay = -1;
    cout << " Testing FIR:" << endl;
    //Switch between FilterType
    switch (iFIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->reset();
    pInstance->init(enumFilterType, fMaxDelay,defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"<< endl;
    
    cout << " Testing IIR:" << endl;
    //Switch between FilterType
    
    pInstance->reset();
    switch (iIIR)
    {
        case 0:enumFilterType = CCombFilterIf::kCombFIR; break;
        case 1:enumFilterType = CCombFilterIf::kCombIIR; break;
    }
    pInstance->init(enumFilterType, fMaxDelay,defaultSampleRateInHz, iTestNumChannels);
    pInstance->setParam(CCombFilterIf::kParamGain, fTestGain);
    pInstance->setParam(CCombFilterIf::kParamDelay, fTestDelay);
    
    
    pInstance->process(pfTestSignal, ppfOutput, iTestSignalLength);
    cout << " output:(print only one channel)" << endl << "\t";
    
    for (int i = 0; i < iTestSignalLength; i++)
    {
        if (i != 0) cout << ",";
        cout << ppfOutput[0][i];
        
    }
    cout << endl;
    cout << " expected:" << endl << "\t" <<"1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"<< endl;
    
//////////////////////////////////////////////////////////////////////////////
//test case finished: using audio data
    if (argc >= 3)
    {
        cout << "---------------------------------------------------------------------------------"<< endl;
        cout << "Test case finishd: using audio data" << endl;
        
        // open the input wave file
        CAudioFileIf::create(phAudioFile);
        phAudioFile->openFile(sInputFilePath, CAudioFileIf::kFileRead);
        if (!phAudioFile->isOpen())
        {
            cout << "Input wave file open error!";
            return -1;
        }
        phAudioFile->getFileSpec(stFileSpec);
        
        // open the output wave file
        CAudioFileIf::create(phAudioOutFile);
        phAudioOutFile->openFile(sOutputFilePath, CAudioFileIf::kFileWrite, &stFileSpec);
        if (!phAudioOutFile->isOpen())
        {
            cout << "Output wave file open error!";
            return -1;
        }
        
        // allocate memory
        ppfAudioData = new float*[stFileSpec.iNumChannels];
        ppfOutput = new float*[stFileSpec.iNumChannels];
        for (int i = 0; i < stFileSpec.iNumChannels; i++)
        {
            ppfAudioData[i] = new float[kBlockSize];
            ppfOutput[i] = new float[kBlockSize];
            
        }
        // get audio data and write it to the output file
        pInstance->reset();
        pInstance->init(enumFilterType, fMaxDelay, stFileSpec.fSampleRateInHz, stFileSpec.iNumChannels);
        pInstance->setParam(CCombFilterIf::kParamGain, fGain);
        pInstance->setParam(CCombFilterIf::kParamDelay, fDelay);
        
        cout << "using input Audio..." << endl;
        while (!phAudioFile->isEof())
        {
            long long               iNumFrames = kBlockSize;
            phAudioFile->readData(ppfAudioData, iNumFrames);
            pInstance->process(ppfAudioData, ppfOutput, iNumFrames);
            phAudioOutFile->writeData(ppfOutput, iNumFrames);
            cout << "\r" << "reading and writing";
            
        }
        cout << "\nreading/writing done in: \t" << (clock() - time)*1.F / CLOCKS_PER_SEC << " seconds." << endl;
        //////////////////////////////////////////////////////////////////////////////
        // clean-up
        CCombFilterIf::destroy(pInstance);
        CAudioFileIf::destroy(phAudioFile);
        CAudioFileIf::destroy(phAudioOutFile);
        
        
        for (int i = 0; i < stFileSpec.iNumChannels; i++)
            delete[] ppfAudioData[i];
        delete[] ppfAudioData;
        ppfAudioData = 0;
        
        for (int i = 0; i < iTestNumChannels; i++)
            delete[] pfTestSignal[i];
        delete[] pfTestSignal;
        pfTestSignal = 0;
        
        for (int i = 0; i < stFileSpec.iNumChannels; i++)
            delete[] ppfOutput[i];
        delete[] ppfOutput;
        ppfOutput = 0;
    }
    else
    {
        //////////////////////////////////////////////////////////////////////////////
        // clean-up only the test case
        CCombFilterIf::destroy(pInstance);
        
        for (int i = 0; i < iTestNumChannels; i++)
            delete[] pfTestSignal[i];
        delete[] pfTestSignal;
        pfTestSignal = 0;
        
        for (int i = 0; i <  iTestNumChannels; i++)
            delete[] ppfOutput[i];
        delete[] ppfOutput;
        ppfOutput = 0;
        
    }
    return 0;
}

void     showClInfo()
{
    cout << "GTCMT MUSI6106 Executable" << endl;
    cout << "(c) 2014-2018 by Alexander Lerch" << endl;
    cout  << endl;

    return;
}

