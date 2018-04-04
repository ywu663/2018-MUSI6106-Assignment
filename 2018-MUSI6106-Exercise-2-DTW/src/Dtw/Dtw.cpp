
#include "Vector.h"
#include "Util.h"

#include "Dtw.h"

CDtw::CDtw( void )
{

}

CDtw::~CDtw( void )
{

}

Error_t CDtw::init( int iNumRows, int iNumCols )
{
    m_i_NumRows = iNumRows;
    m_iNumCols = iNumCols;
    costMatrix = new float*[m_i_NumRows];
    for (int i = 0; i < m_i_NumRows; i++) {
        costMatrix[i] = new float[iNumCols];
        for (int j = 0; j < m_iNumCols; j++) {
            costMatrix[i][j] = 0;
        }
    }
    return kNoError;
}

Error_t CDtw::reset()
{
    return kNoError;
}

Error_t CDtw::process(float **ppfDistanceMatrix)
{
    costMatrix[0][0] = ppfDistanceMatrix[0][0];
    return kNoError;
}

int CDtw::getPathLength()
{    
    return 0;
}

float CDtw::getPathCost() const
{
    return 0.f;
}

Error_t CDtw::getPath( int **ppiPathResult ) const
{
    return kNoError;
}

