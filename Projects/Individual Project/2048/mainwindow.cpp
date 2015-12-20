#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <iostream>
#include <QDataStream>
#include <QFile>
#include <QTextStream>
#include <QMenuBar>
#include <QString>
#include <QDebug>
#include <QTextEdit>
#include <QDir>
#include <QCoreApplication>
#include <QRegularExpression>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createboard();
    gamehelper = new helper();
}

void MainWindow::help()
{
    QFile file(":/tile/image/directions.txt");

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QString strFile1(file.readAll());
    file.close();

    QTextEdit* edit = new QTextEdit();
    edit->setFixedSize(300,200);
    edit->setPlainText(strFile1);
    edit->setWindowTitle("Directions on How to Play 2048");
    edit->show();

//    QString text = "";
//    QFile file("directions.txt");
//    if (!file.exists()) qDebug() << "DNE";
//    if(!file.open(QFile::ReadOnly))
//    {
//        qDebug() << " Could not open the file for reading";
//        return;
//    }

//    QTextStream in(&file);

//    while(!in.atEnd()){
//        QString line = in.readLine();
//        text.append(line);
//    }

//    file.close();

//    helpscreen = new QWidget;
//    hlayout = new QVBoxLayout;
//    hnameLabel = new QLabel();
//    okb = new QPushButton;
//    hlayout->addWidget(hnameLabel);
//    hlayout->addWidget(okb);
//    connect(okb,SIGNAL(clicked()),this,SLOT(close()));
//    okb->setText("Ok");
//    helpscreen->setLayout(hlayout);
//    helpscreen->show();
}

void MainWindow::backupGrid()
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            btile[i][j]=tile[i][j]->getNumber();
        }
    }
    bscore = score;
}

void MainWindow::undo()
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            tile[i][j]->setNumber(btile[i][j]);
        }
    }
    score = bscore;
    emit changed(score);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createboard()
{
    tile[0][0] = ui->tile1;
    tile[0][1] = ui->tile2;
    tile[0][2] = ui->tile3;
    tile[0][3] = ui->tile4;
    tile[1][0] = ui->tile5;
    tile[1][1] = ui->tile6;
    tile[1][2] = ui->tile7;
    tile[1][3] = ui->tile8;
    tile[1][3] = ui->tile8;
    tile[2][0] = ui->tile9;
    tile[2][1] = ui->tile10;
    tile[2][2] = ui->tile11;
    tile[2][3] = ui->tile12;
    tile[3][0] = ui->tile13;
    tile[3][1] = ui->tile14;
    tile[3][2] = ui->tile15;
    tile[3][3] = ui->tile16;
    startGame();
}

void MainWindow::reset()
{
    if(endgame != NULL ){
        endgame->hide();
    }

    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            tile[i][j]->setNumber(0);
    startGame();
}

void MainWindow::startGame()
{
    score=0;
    bscore = 0;
    connect(this,SIGNAL(changed(int)),ui->scoreDisplay,SLOT(display(int)));
    emit changed(score);

    int i, j, k;
    for (int x=0; x<2; x++){
        do {
            i = rand()%4;
            j = rand()%4;
        } while(tile[i][j]->getNumber());
        k = rand()%10;
        if (k<2)
            tile[i][j]->setNumber(4);
        else
            tile[i][j]->setNumber(2);
        btile[i][j]=tile[i][j]->getNumber();
    }
}

void MainWindow::quits()
{
    qApp->quit();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    backupGrid();
    switch(event->key())
    {
        case Qt::Key_Up:
        {
            if(movepossible())
                 moveUp();
            else endGame(1);
            break;
        }
        case Qt::Key_Down:
        {
            if(movepossible())
             moveDown();
            else endGame(1);
            break;
        }
        case Qt::Key_Left:
        {
            if(movepossible())
                moveLeft();
            else endGame(1);
            break;
        }
        case Qt::Key_Right:
        {
            if(movepossible())
                moveRight();
            else endGame(1);
            break;
        }
        default: QWidget::keyPressEvent(event);
    }
}

bool MainWindow::movepossible()
{
    if(isFull())
    {
        for(int i = 0;i < 4; i++)
            for(int j = 0;j < 3;j++)
                if(tile[i][j]->getNumber() ==tile[i][j+1]->getNumber())
                    return true;

        for(int j = 0;j < 4; j++)
            for(int i = 0;i < 3;i++)
                if(tile[i][j]->getNumber() ==tile[i+1][j]->getNumber())
                   return true;
        return false;
    }
    else
        return true;

}

void MainWindow::randomtile()
{
    QVector<Tile *> empty;
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            if(tile[i][j]->isEmpty())
                empty.append(tile[i][j]);
    int n =(rand()%2+1)*2;
    int emptyBoxCount =empty.count();
    if(emptyBoxCount)
        empty.at(rand()%emptyBoxCount)->setNumber(n);
}

bool MainWindow::isFull()
{
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            if(tile[i][j]->isEmpty())
                return false;
    return true;
}

void MainWindow::exchange(Tile *Box1, Tile *Box2)
{
     int Num1 = Box1->getNumber();
     int Num2 = Box2->getNumber();
     Box1->setNumber(Num2);
     Box2->setNumber(Num1);
}

void MainWindow::moveUp()
{
    emptytileMoveDown();
    for(int j = 0;j < 4;j++)
        for(int i = 3;i > 0;i--)
            if(!tile[i][j]->isEmpty())
            {
                if(tile[i][j]->getNumber() == tile[i-1][j]->getNumber())
                {
                    tile[i][j]->setNumber(0);
                    tile[i-1][j]->upgrade();
                    score+=tile[i-1][j]->getNumber();
                    emit changed(score);
                    if(tile[i-1][j]->getNumber() == 2048)
                        endGame(2);
                }
            }

    emptytileMoveDown();
    randomtile();
}

void MainWindow::moveRight()
{
    emptytileMoveLft();
    for(int i = 0;i < 4; i++)
        for(int j = 0;j < 3;j++)
            if(!tile[i][j]->isEmpty())
            {
                if(tile[i][j]->getNumber()== tile[i][j+1]->getNumber())
                {
                    tile[i][j]->setNumber(0);
                    tile[i][j+1]->upgrade();
                    score += tile[i][j+1]->getNumber();
                    emit changed(score);
                    if(tile[i][j+1]->getNumber() == 2048)
                        endGame(2);
                }
            }

    emptytileMoveLft();
    randomtile();
}

void MainWindow::moveLeft()
{
    emptytileMoveRight();
    for(int i = 0;i < 4;i++)
        for(int j = 3;j > 0;j--)
            if(!tile[i][j]->isEmpty())
            {
                if(tile[i][j]->getNumber()== tile[i][j-1]->getNumber())
                {
                    tile[i][j]->setNumber(0);
                    tile[i][j-1]->upgrade();
                    score += tile[i][j-1]->getNumber();
                    emit changed(score);
                    if(tile[i][j-1]->getNumber() == 2048)
                        endGame(2);
                }
            }

    emptytileMoveRight();
    randomtile();
}

void MainWindow::moveDown()
{
    emptytileMoveUp();
    for(int j = 0;j < 4;j++)
        for(int i = 0;i < 3;i++)
            if(!tile[i][j]->isEmpty())
            {
                if(tile[i][j]->getNumber()== tile[i+1][j]->getNumber())
                {
                    tile[i][j]->setNumber(0);
                    tile[i+1][j]->upgrade();
                    score += tile[i+1][j]->getNumber();
                    emit changed(score);
                    if(tile[i+1][j]->getNumber() == 2048)
                        endGame(2);
                }
            }

    emptytileMoveUp();
    randomtile();
}

void MainWindow::emptytileMoveLft()
{
    for(int i = 0;i < 4;i++)
        for(int j = 3;j > 0;j--)
            if(tile[i][j]->isEmpty())
                for(int k=j;k>0;k--)
                    exchange(tile[i][k],tile[i][k-1]);
}

void MainWindow::emptytileMoveDown()
{
    for(int j = 0;j < 4;j++)
        for(int i = 0;i < 3;i++)
            if(tile[i][j]->isEmpty())
                for(int k=i;k<3;k++)
                     exchange(tile[k][j],tile[k+1][j]);
}

void MainWindow::emptytileMoveRight()
{
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 3;j++)
            if(tile[i][j]->isEmpty())
                for(int k=j;k< 3;k++)
                    exchange(tile[i][k],tile[i][k+1]);
}

void MainWindow::emptytileMoveUp()
{
    for(int j = 0;j < 4;j++)
        for(int i = 3;i > 0;i--)
            if(tile[i][j]->isEmpty())
                for(int k= i;k> 0;k--)
                    exchange(tile[k][j],tile[k-1][j]);
}

void MainWindow::endGame(int ch)
{
    endgame= new QWidget;
    layout = new QVBoxLayout;
    nameLabel = new QLabel;
    scoreLabel = new QLabel;
    name = new QLineEdit;
    resetb = new QPushButton;
    exit = new QPushButton;
    word =new QLabel;
    layout->addWidget(scoreLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(name);
    layout->addWidget(word);
    layout->addWidget(resetb);
    layout->addWidget(exit);
    QObject::connect(resetb,SIGNAL(clicked()),this,SLOT(reset()) );
    QObject::connect(exit,SIGNAL(clicked()),this,SLOT(addInfo()));
    //QObject::connect(exit,SIGNAL(clicked()),this,SLOT(quits()) );
    QString s = QString::number(score);
    scoreLabel->setText("Score: " + s);
    nameLabel->setText("Name: ");
    resetb->setText("Reset");
    exit->setText("Save and Exit");
    if(ch==2)
        word->setText("2048 Win!");
    else
        word->setText("Gameover");
    endgame->setLayout(layout);

    QRegExp regExp("^\s*[A-Z][a-z]{1,14}\s*$");
    name->setValidator(new QRegExpValidator(regExp, this));
    endgame->show();
}

void MainWindow::addInfo()
{
//    QFile file("info.txt");
//    if (!file.open(QIODevice::WriteOnly))
//    {
//        std::cerr << "Cannot open file for writing: ";
//             //<< qPrintable(file.errorString()) << endl;
//        return;
//    }
//    QTextStream out(&file);
//    out << "name" << "score: " << endl;
    gamehelper->save(name->text(),score);
    emit quits();
}

void MainWindow::on_actionUndo_triggered()
{
    undo();
}

void MainWindow::on_actionHelp_triggered()
{
    help();
}

void MainWindow::on_actionNew_Game_triggered()
{
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            tile[i][j]->setNumber(0);
    startGame();
}
