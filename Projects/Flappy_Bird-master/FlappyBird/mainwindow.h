#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "mainscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    /*Path to the score sound track*/
    const QString SCORE_S_FILE_NAME = "qrc:/SoundTracks/Score.mp3";

    /*The number of flowers the player has to pass to be leveled up*/
    const int NUMBER_OF_FLOWERS_PER_LEVEL = 10;

    /*Main UI*/
    Ui::MainWindow *ui;

    /*The fundamental graphics scene of the game*/
    MainScene *mainScene;

    /*The current score of a game*/
    int crScore = 0;

    /*The media player of the scoring sound*/
    QMediaPlayer *scoreMs;

public:

    /*The primary constructor of this window*/
    explicit MainWindow(QWidget *parent = 0);

    /*Main window destructor*/
    ~MainWindow();

protected:

    /*This function waits for a key press event that belongs to the main window*/
    void keyPressEvent(QKeyEvent* event);

signals:

    /*This function is called when the Space Bar key was pressed*/
    void pressSpaceKey();

    /*This function is called when the bird collides with a flower*/
    void processCollision();

    /*This function is called when the bird passed NUMBER_OF_FLOWERS_PER_LEVEL flowers*/
    void levelUp();

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

    /*Increase the socre when the bird passes a column of flower*/
    void updateScore();

    /*The auto-generated getter of the current score*/
    int getCrScore() const;

    /*Clean up all the components to prepare for a new game*/
    void restartUI();
};

#endif // MAINWINDOW_H
