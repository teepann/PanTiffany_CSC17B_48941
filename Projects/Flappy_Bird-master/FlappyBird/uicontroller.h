#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include <QTimer>
#include "mainwindow.h"
#include <QMediaPlayer>
#include "difficultydialog.h"
#include "godialog.h"

/**
 * @brief The SceneController class
 * This is the primary controller of the GUI.
 * It controls all the behaviors on the main window and its scene
 */
class UIController : public QObject
{
    Q_OBJECT

private:

    /*The minimum miliseconds for creating flowers*/
    const int MIN_TIME_IN_MIL = 1500;

    /*The maximum miliseconds for creating flowers*/
    const int MAX_TIME_IN_MIL = 5000;

    /*The default miliseconds for the bird fall down*/
    const int BIRD_FALLING_SPEED = 200;

    /*Path to the back ground sound track*/
    const QString BG_S_FILE_NAME = "qrc:/SoundTracks/BGround.mp3";

    /*Path to the game-over sound track*/
    const QString GO_S_FILE_NAME = "qrc:/SoundTracks/EndGame.mp3";

    /*The main window of Flappy Bird*/
    MainWindow *mainWindow;

    /*The start menu of a game*/
    DifficultyDialog *dDialog;

    /*The game-over dialog*/
    GODialog *gODialog;

    /*This timer is used for controlling the creation of flowers*/
    QTimer *cFlowerTimer;

    /*This timer is used for controlling the movement of flowers*/
    QTimer *mFlowerTimer;

    /*This timer is used for controlling the gravity on the bird*/
    QTimer *gBirdTimer;

    /*The media player of the back ground music*/
    QMediaPlayer *bgMusic;

    /*The media player of the game-over sound*/
    QMediaPlayer *endMs;

    /*Identifying the current game mode*/
    bool isGameStarted;

public:
    /*The constructor of this main UI controller*/
    explicit UIController(QObject *parent = 0);

signals:

public slots:

    /*Randomly ask for new flowers to add to the main scene*/
    void createFlowers();

    /*Processing the items in the scene according to the key press*/
    void processSpaceKeyPress();

    /*This function is called when the bird collides with a flower*/
    void processCollision();

    /*This function is called when the back ground music was stoped*/
    void stateChanged(QMediaPlayer::State newState);

    /*This function is called after the user has chosen the difficulty */
    void startGame();

    /*This function is called after the user has chosen to restart the game */
    void restart();

    /*This function handles the level-up event from the main window*/
    void levelUp();

private:

    /*Connect all the subsystems to this UI controller*/
    void connectSystems();

};

#endif // UICONTROLLER_H
