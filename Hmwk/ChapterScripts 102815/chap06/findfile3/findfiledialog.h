#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class FindFileDialog : public QDialog
{
    Q_OBJECT

public:
    FindFileDialog(QWidget *parent = 0);

private:
    QLabel *namedLabel;
    QLabel *lookInLabel;
    QLineEdit *lookInLineEdit;
    QLineEdit *namedLineEdit;
    QCheckBox *subfoldersCheckBox;
    QTableWidget *tableWidget;
    QLabel *messageLabel;
    QPushButton *findButton;
    QPushButton *stopButton;
    QPushButton *closeButton;
    QPushButton *helpButton;
};

#endif
