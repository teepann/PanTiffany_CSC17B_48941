#include "widget.h"
#include "ui_widget.h"
#include <qpushbutton>
#include <qwidget.h>
#include <qhboxlayout>
#include <iostream>
#include <QDataStream>
#include <QFile>
#include <QTextStream>
#include <QMenuBar>

using namespace std;

Widget::Widget(QWidget *parent) :QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->pushButton->setFixedWidth(10);
    score = 0;
    createboard();

    /*QVBoxLayout vbox;
    this->setLayout(vbox);
    QMenuBar menuBar;
    vbox.addWidget(menuBar);
    menuBar.addMenu('File');
    menuBar.addMenu('Edit');*/
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
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

void Widget::moveUp()
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

void Widget::moveRight()
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

void Widget::moveLeft()
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

void Widget::moveDown()
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

bool Widget::movepossible()
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

void Widget::endGame(int ch)
{

        endgame= new QWidget;
        layout = new QVBoxLayout;
        nameLabel = new QLabel();
        name = new QLineEdit;
        resetb = new QPushButton;
        exit = new QPushButton;
        word =new QLabel;
        layout->addWidget(nameLabel);
        layout->addWidget(name);
        layout->addWidget(word);
        layout->addWidget(resetb);
        layout->addWidget(exit);
        QObject::connect(resetb,SIGNAL(clicked()),this,SLOT(reset()) );
        QObject::connect(exit,SIGNAL(clicked()),this,SLOT(quits()) );
        QObject::connect(exit,SIGNAL(clicked()),this,SLOT(addInfo()));
        nameLabel->setText("Name: ");
        resetb->setText("Reset");
        exit->setText("Exit");
        if(ch==2)
            word->setText("2048 Win!");
        else
            word->setText("Gameover");
        endgame->setLayout(layout);
        endgame->show();

        QFile file("C:\\Users\\Tiffany\\Desktop\\17b\\Projects\\IndividualProject_2048\\info.txt");
        if (!file.open(QIODevice::WriteOnly))
        {
            cerr << "Cannot open file for writing: "
                 << qPrintable(file.errorString()) << endl;
            return;
        }
        QTextStream out(&file);
        out << "name" << "score: " << endl;

}

void Widget::startGame()
{ 
    score=0;
    connect(this,SIGNAL(changed(int)),ui->score,SLOT(display(int)));
    emit changed(score);
    int n = 2;
    for(int i = 0;i < 2;i++)
    {
        int x = rand()%4;
        int y = rand()%4;
        if(tile[x][y]->isEmpty())       
            tile[x][y]->setNumber(n);       
    }
}

void Widget::reset()
{
    endgame->hide();
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            tile[i][j]->setNumber(0);
    startGame();
}

void Widget::addInfo()
{
    file->setFileName("info.dat");
    if(!file->open(QIODevice::WriteOnly)){
        cerr << "Cannot open file for writing: "
             << qPrintable(file->errorString()) << endl;
        return;
    }
    QDataStream out(file);
    out.setVersion(QDataStream::Qt_5_2);
    out << name->text();
}

void Widget::createboard()
{
    tile[0][0] = ui->tile1;
    tile[0][1] = ui->tile2;
    tile[0][2] = ui->tile3;
    tile[0][3] = ui->tile4;
    tile[1][0] = ui->tile5;
    tile[1][1] = ui->tile6;
    tile[1][2] = ui->tile7;
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

void Widget::quits()
{
    qApp->quit();
}

void Widget::randomtile()
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


bool Widget::isFull()
{
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            if(tile[i][j]->isEmpty())
                return false;
    return true;
}

void Widget::exchange(Tile *Box1, Tile *Box2)
{
     int Num1 = Box1->getNumber();
     int Num2 = Box2->getNumber();
     Box1->setNumber(Num2);
     Box2->setNumber(Num1);
}

void Widget::emptytileMoveLft()
{
    for(int i = 0;i < 4;i++)
        for(int j = 3;j > 0;j--)
            if(tile[i][j]->isEmpty())
                for(int k=j;k>0;k--)
                    exchange(tile[i][k],tile[i][k-1]);
}

void Widget::emptytileMoveDown()
{
    for(int j = 0;j < 4;j++)   
        for(int i = 0;i < 3;i++)       
            if(tile[i][j]->isEmpty())           
                for(int k=i;k<3;k++)               
                     exchange(tile[k][j],tile[k+1][j]);
}

void Widget::emptytileMoveRight()
{
    for(int i = 0;i < 4;i++)    
        for(int j = 0;j < 3;j++)       
            if(tile[i][j]->isEmpty())            
                for(int k=j;k< 3;k++)               
                    exchange(tile[i][k],tile[i][k+1]);
}

void Widget::emptytileMoveUp()
{
    for(int j = 0;j < 4;j++)
        for(int i = 3;i > 0;i--)        
            if(tile[i][j]->isEmpty())            
                for(int k= i;k> 0;k--)               
                    exchange(tile[k][j],tile[k-1][j]);
}

