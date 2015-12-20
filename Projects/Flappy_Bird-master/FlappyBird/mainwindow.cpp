#include "mainwindow.h"
#include "ui_mainwindow.h"

/*Reference to the function declaration*/
int MainWindow::getCrScore() const
{
    return crScore;
}

/**
 * @brief MainWindow::restartUI
 */
void MainWindow::restartUI()
{
    //Ask main scene to reset its components
    mainScene->restartScene();

    //Reset the score
    crScore = 0;
    ui->lcdScore->display(crScore);
    ui->lcdScore->hide();
}

/*Reference to the function declaration*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set a permanent size for this main window and its graphics view
    setFixedSize(geometry().width(),geometry().height());
    ui->graphicsView->setFixedSize(ui->graphicsView->geometry().width()
                                   ,ui->graphicsView->geometry().height());

    //Setting up the main scene in this window
    mainScene = new MainScene(this);
    mainScene->setSceneRect(ui->graphicsView->geometry().topLeft().x()
                            ,ui->graphicsView->geometry().topLeft().y()
                            ,ui->graphicsView->geometry().width()
                            ,ui->graphicsView->geometry().height());

    ui->graphicsView->setScene(mainScene);

    //Setup the score panel before getting the game started
    ui->lcdScore->setStyleSheet("QLCDNumber {color: blue;}");
    ui->lcdScore->hide();

    //Setup the scoring sound
    scoreMs = new QMediaPlayer();
    scoreMs->setMedia(QUrl(SCORE_S_FILE_NAME));

}

/*Reference to the function declaration*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*Reference to the function declaration*/
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Check if the space bar was pressed
    if (event->key() == Qt::Key_Space){
        emit pressSpaceKey();
    }
}

/*Reference to the function declaration*/
void MainWindow::updateScore()
{
    ui->lcdScore->display(++crScore);

    scoreMs->play();

    if ((crScore%NUMBER_OF_FLOWERS_PER_LEVEL) == 0){
        emit levelUp();
    }
}

/*Reference to the function declaration*/
void MainWindow::createFlowers()
{
    mainScene->createFlowers();
}

/*Reference to the function declaration*/
void MainWindow::play()
{
    //Start scoring the game
    ui->lcdScore->show();

    //Ask the main scene to animate the its components
    mainScene->play();
}

/*Reference to the function declaration*/
void MainWindow::freeFallBird()
{
    mainScene->freeFallBird();
}

/*Reference to the function declaration*/
void MainWindow::flyUpBird()
{
    mainScene->flyUpBird();
}

/*Reference to the function declaration*/
void MainWindow::moveFlowers()
{
    mainScene->moveFlowers();
}




