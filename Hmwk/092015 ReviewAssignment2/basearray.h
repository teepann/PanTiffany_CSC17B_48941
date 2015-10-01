#ifndef BASEARRAY_H
#define BASEARRAY_H
#include "abstractarray.h"
#include <string>

class BaseArray : public AbstractArray
{
public:
    BaseArray();
    //Constructor
    BaseArray(int r, int c) : AbstractArray(r, c)
    {
       array = new int*[r];
       for (int i = 0; i<r; i++)
         array[i] = new int[c];
    }
    //destructor
    ~BaseArray()
    {
       for (int i = 0; i<nRows; i++)
           delete[] array[i];
       delete[]array;
    }
    //Override fillarray
    void fillarray();
    std::string toString();
};

#endif // BASEARRAY_H
