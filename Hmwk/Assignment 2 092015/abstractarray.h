#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H


class AbstractArray
{
protected:
    int nRows, nCols; //holds number of rows and columns
    int **array; //2D array
public:
    AbstractArray();
    //Constructor
    AbstractArray(int r, int c)
        { set(r, c); }
    //set variables
    void set(int r, int c)
        { nRows = r; nCols = c;}
    //pure abstract
    virtual void fillarray() = 0;
};

#endif // ABSTRACTARRAY_H
