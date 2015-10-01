/*
 * Tiffany Pan
 * September 20th, 2015
 * Create a 2-Dim Dynamic Array
 */
//System Libraries
#include <QApplication>
#include "derivedarray.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DerivedArray ary(15,10);
    ary.fillarray();
    ary.toString();
    ary.toPrint();
    return a.exec();
}
