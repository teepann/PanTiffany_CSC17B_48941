#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mainscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*The primary constructor of this window*/
    explicit MainWindow(QWidget *parent = 0);

    /*Main window destructor*/
    ~MainWindow();

private:

    /*Main UI*/
    Ui::MainWindow *ui;

    /*The fundamental graphics scene of the game*/
    MainScene *mainScene;    

    /*Timer for pause function*/
    QTimer *timer;

protected:

    /*This function waits for a key press event that belongs to the main window*/
    void keyPressEvent(QKeyEvent* event);

signals:

    /*This function is called when the Space Bar key was pressed*/
    void pressSpaceKey();

    /*This function is called when the bird collides with a flower*/
    void processCollision();

public slots:

    /*This function asks main scene to move flowers when the GUI thread is running*/
    void moveFlowers();

    /*This function asks main scene to apply the gravity on the bird when the GUI thread is running*/
    void freeFallBird();

public:

    /*This function asks main scene to create new flowers when the GUI thread is running*/
    void createFlowers();

    /*This function asks main scene to start the game when the GUI thread is running*/
    void play();

     /*This function asks main scene to let the bird fly-up when the GUI thread is running*/
    void flyUpBird();
};

#endif // MAINWINDOW_H
