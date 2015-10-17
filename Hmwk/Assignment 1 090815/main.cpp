/*
 * Tiffany Pan
 * September 9th, 2015
 * Create a 2-Dim Dynamic Array
 *
 */
//System Libraries
#include <QApplication> //for QApplication
#include <QLabel> //for QLabel
#include <iostream> //for input/output file library
using namespace std;

//User Libraries
#include "array.h"

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char *argv[])
{
    //Start the Windowed Applications
    QApplication a(argc, argv);
    //Create an instance of an Array filled with random numbers
    Array ary(10,10);
    //convert to array of strings
    string array1=ary.toString();
    //Add a label
    QLabel *label = new QLabel(array1.c_str());
    //Show the label
    label->show();
    //Send to the controller
    return a.exec();


}
