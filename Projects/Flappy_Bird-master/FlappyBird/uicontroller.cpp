#include "uicontroller.h"

/**
 * Reference to the function declaration
 * @brief UIController::UIController
 * @param parent
 */
UIController::UIController(QObject *parent) : QObject(parent)
{
    //Initialize the main window with its components
    mainWindow = new MainWindow();
    mainWindow->show();

    //Intialized the start game menu
    dDialog = new DifficultyDialog(mainWindow);

    //Intialized the end game menu
    gODialog = new GODialog(mainWindow);

    //Seeding the value for a random
    qsrand(time(NULL));

    //Initializing all the timers
    cFlowerTimer = new QTimer(this);
    mFlowerTimer = new QTimer(this);
    gBirdTimer = new QTimer(this);

    //Waiting for a user to start the game
    isGameStarted = false;

    //Setup the multimedia players
    bgMusic = new QMediaPlayer();
    endMs = new QMediaPlayer();

    bgMusic->setMedia(QUrl(BG_S_FILE_NAME));
    endMs->setMedia(QUrl(GO_S_FILE_NAME));

    //Connect all the components together
    connectSystems();
}

/**
 * Reference to the function declaration
 * @brief UIController::createNewFLowers
 */
void UIController::createFlowers()
{
    //Randomize the time for creating new flowers
    cFlowerTimer->stop();
    mainWindow->createFlowers();
    cFlowerTimer->start(MIN_TIME_IN_MIL + (qrand()%(MAX_TIME_IN_MIL - MIN_TIME_IN_MIL + 1)));
}

/**
 * Reference to the function declaration
 * @brief UIController::processKeyPress
 */
void UIController::processSpaceKeyPress()
{
    if (!isGameStarted){ //Starting the game at the first time

        isGameStarted = true;

        //Populate the difficulty dialog UI
        dDialog->show();


        //Using SIGNAL-SLOT to replay the back ground music
        connect(bgMusic,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stateChanged(QMediaPlayer::State)));
        //Play the back ground music
        bgMusic->play();

    }else { //Processing the bird movements

        //Stop free-fall for fly-up
        gBirdTimer->stop();
        mainWindow->flyUpBird();

        //Start free-fall again
        gBirdTimer->start(BIRD_FALLING_SPEED);
    }

}

/**
 * Reference to the function declaration
 * @brief UIController::processCollision
 */
void UIController::processCollision()
{

    //Stop creating and moving flowers
    cFlowerTimer->stop();
    mFlowerTimer->stop();

    //Stop letting the bird fall down
    gBirdTimer->stop();

    /*Process media affects*/
    //Stop using SIGNAL-SLOT to replay the back ground music
    disconnect(bgMusic,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stateChanged(QMediaPlayer::State)));
    bgMusic->stop();
    endMs->play();

    //Populate the game-over UI
    gODialog->populateUI(mainWindow->getCrScore());
}

/**
 * Reference to the function declaration
 * @brief UIController::stateChanged
 * @param newState
 */
void UIController::stateChanged(QMediaPlayer::State newState)
{
    if (newState == QMediaPlayer::StoppedState){
        bgMusic->play(); // Replay the music
    }
}

/**
 * Reference to the function declaration
 * @brief UIController::startGame
 */
void UIController::startGame()
{
    //Hide the difficulty dialog
    dDialog->hide();

    //Let flowers appear and move in the scene
    cFlowerTimer->start(MIN_TIME_IN_MIL);
    mFlowerTimer->start(GameLevel::getInstance().getFlowerSpeed());

    //Let the bird free fall
    gBirdTimer->start(BIRD_FALLING_SPEED);

    //Put the bird in the right position to start the game
    mainWindow->play();

}

/**
 * Reference to the function declaration
 * @brief UIController::restart
 */
void UIController::restart()
{
    mainWindow->restartUI();
    isGameStarted = false;
}

/**
 * Reference to the function declaration
 * @brief UIController::levelUp
 */
void UIController::levelUp()
{
    int crTimer = mFlowerTimer->interval();

    if ((crTimer--) > 1){
       mFlowerTimer->setInterval(crTimer);
    }
}

/**
 * @brief UIController::connectSystems
 */
void UIController::connectSystems()
{
    //Connecting timer to the behaviors of flowers in the main scene
    connect(cFlowerTimer,SIGNAL(timeout()),this,SLOT(createFlowers()));
    connect(mFlowerTimer,SIGNAL(timeout()),mainWindow,SLOT(moveFlowers()));

    //Connecting timer to the behaviors of the bird
    connect(gBirdTimer,SIGNAL(timeout()),mainWindow,SLOT(freeFallBird()));

    //Getting connect to the key event of the main window
    connect(mainWindow,SIGNAL(pressSpaceKey()),this,SLOT(processSpaceKeyPress()));

    //Getting a notify from the main window for a collision
    connect(mainWindow,SIGNAL(processCollision()),this,SLOT(processCollision()));

    //Register with the main window to receive a level-up signal
    connect(mainWindow,SIGNAL(levelUp()),this,SLOT(levelUp()));

    //Register with the difficulty dialog to receive a start-game signal
    connect(dDialog,SIGNAL(startGame()),this,SLOT(startGame()));

    //Register with the game-over dialog to receive a restart-game signal
    connect(gODialog,SIGNAL(restart()),this,SLOT(restart()));

}



