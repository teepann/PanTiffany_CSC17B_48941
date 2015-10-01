#ifndef DERIVEDARRAY_H
#define DERIVEDARRAY_H
#include "basearray.h"

class DerivedArray : public BaseArray
{
public:
    DerivedArray();
    DerivedArray(int r, int c) : BaseArray(r, c)
        { }
    ~DerivedArray();
    void toPrint();

};

#endif // DERIVEDARRAY_H
