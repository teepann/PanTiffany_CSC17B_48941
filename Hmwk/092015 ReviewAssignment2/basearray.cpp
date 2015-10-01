#include "basearray.h"
#include <string>
#include <sstream>
#include <cstdlib> //for random

std::string BaseArray::toString()
{
    std::string stringArray="";
    for(int i=0; i<nRows; i++)
    {
        for(int j=0; j<nCols; j++)
        {
            std::stringstream ss;
            ss<<array[i][j];
            stringArray+=ss.str()+" ";
        }
        stringArray+="\n";
    }
    return stringArray;
}
void BaseArray::fillarray()
{
    for(int i=0; i<nRows; i++)
    {
        for(int j=0; j<nCols; j++)
        {
            //fill array with random 2 digit numbers
            array[i][j]=rand()%90+10;
        }
    }
}
