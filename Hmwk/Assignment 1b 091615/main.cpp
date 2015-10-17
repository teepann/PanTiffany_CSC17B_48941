/*
 * Tiffany Pan
 * September 16th, 2015
 * Create a 2-Dim Dynamic Array and GUI
 *
 */
//System Libraries
#include <QApplication> //for QApplication
#include <QLabel> //for QLabel
#include <QGridLayout>
#include <iostream> //for input/output file library
using namespace std;

//User Libraries
#include "array.h"

//Global Constants
//Function Prototypes
//Execution begins here
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create an instance of an Array filled with random numbers
    Array ary(10,10);
    //convert to array of strings
    string array1=ary.toString();
    //Create a window
    QWidget window;
    window.setWindowTitle("Hello World Program");
    window.setMinimumSize(200,200);
    //Have a layout for window
    QGridLayout *mainLayout = new QGridLayout(&window);
    //Add a label
    QLabel *label = new QLabel(array1.c_str());
    //add the label to the layout
    mainLayout->addWidget(label,0,0);
    //show the window
    window.show();
    //execute the application
    return a.exec();
}
