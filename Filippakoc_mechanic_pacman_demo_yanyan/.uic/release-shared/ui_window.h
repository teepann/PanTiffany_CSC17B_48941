/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Fri Nov 16 11:56:24 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QDialog *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName(QString::fromUtf8("window"));
        window->resize(450, 550);
        window->setMinimumSize(QSize(450, 550));
        window->setMaximumSize(QSize(450, 550));
        graphicsView = new QGraphicsView(window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 450, 550));
        graphicsView->setMinimumSize(QSize(450, 550));
        graphicsView->setMaximumSize(QSize(450, 550));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QDialog *window)
    {
        window->setWindowTitle(QApplication::translate("window", "Filippakoc_pacman_demo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
