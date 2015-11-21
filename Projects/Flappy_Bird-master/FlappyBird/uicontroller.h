#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include <QTimer>
#include "mainwindow.h"
#include "startmenu.h"
#include "endmenu.h"

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

    /*The default (easy level) miliseconds for moving flowers*/
    int flowerSpeed = 12;

    /*The default (easy level) miliseconds for the bird fall down*/
    int birdFallingSpeed = 170;

    /*The main window of Flappy Bird*/
    MainWindow *mainWindow;

    /*The start menu*/
    StartMenu *startMenu;

    /*The end menu*/
    EndGMenu *endMenu;

    /*This timer is used for controlling the creation of flowers*/
    QTimer *cFlowerTimer;

    /*This timer is used for controlling the movement of flowers*/
    QTimer *mFlowerTimer;

    /*This timer is used for controlling the gravity on the bird*/
    QTimer *gBirdTimer;

    /*Identifying the current game mode*/
    bool isGameStarted;

public:
    /*The constructor of this main UI controller*/
    explicit UIController(QObject *parent = 0);

    /*Change speed for flower and bird based on difficultly level*/
    void changeDifficulty(int, int);

signals:

public slots:

    /*Randomly ask for new flowers to add to the main scene*/
    void createFlowers();

    /*Processing the items in the scene according to the key press*/
    void processSpaceKeyPress();

    /*This function is called when the bird collides with a flower*/
    void processCollision();
};

#endif // UICONTROLLER_H
