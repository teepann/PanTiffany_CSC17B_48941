#include "derivedarray.h"
#include <iostream>
#include "basearray.h"

void DerivedArray::toPrint()
{
        for(int i=0; i<nRows; i++)
        {
            for(int j=0; j<nCols; j++)
            {
                std::cout<<array[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
}

