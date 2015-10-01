#ifndef ARRAY_H
#define ARRAY_H
//System Libraries
#include <string> //string library

class Array
{
private:
    //Array class has the following properties:
    int nRows;
    int nCols;
    int **array;
public:
    //Array class has the following behaviors:
    Array(int nRows, int nCols);
    ~Array();
    void printArray();
    std::string toString();
};

#endif // ARRAY_H
