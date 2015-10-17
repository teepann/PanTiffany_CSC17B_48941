//System Libraries
#include <cstdlib> //for rand
#include <iostream> //input/output file library
#include <sstream> //for stringstream
//Header files
#include "array.h"

//constructor for Array
Array::Array(int nRows, int nCols)
{
    this->nRows=nRows;
    this->nCols=nCols;
    array=new int*[nRows];
    for(int i=0; i<nRows; i++)
    {
        array[i]=new int[nCols];
    }
    for(int i=0; i<nRows; i++)
    {
        for(int j=0; j<nCols; j++)
        {
            //fill array with random 2 digit numbers
            array[i][j]=rand()%90+10;

        }
    }
}
//Destructor to deallocate memory
Array::~Array()
{
    for(int i=0; i<nRows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

//return a string with the contents of the array
std::string Array::toString()
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
//test to print out the array of ints
//void Array::printArray()
//{
//    for(int i=0; i<nRows; i++)
//    {
//        for(int j=0; j<nCols; j++)
//        {
//            std::cout<<array[i][j]<<" ";

//        }
//        std::cout<<std::endl;
//    }
//    std::cout<<std::endl;
//}
