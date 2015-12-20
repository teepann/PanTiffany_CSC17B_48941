#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <ctime>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <gamelevel.h>
#include <cmath>

/**
 * @brief The MainScene class
 * This is the main graphics scene of the game
 * It is used to manage all the moving items (the birds and flowers) as well as the background
 */
class MainScene : public QGraphicsScene
{

private:

    /*Path to the back ground image*/
    const QString BG_FILE_NAME = ":/Images/BackGround.png";

    /*Path to the upward flower image*/
    const QString UF_FILE_NAME = ":/Images/UpwardFlower.png";

    /*Path to the downward flower image*/
    const QString DF_FILE_NAME = ":/Images/DownwardFlower.png";

    /*Path to the flappig bird image*/
    const QString FB_FILE_NAME = ":/Images/FlappingBird.gif";

    /*The minimum height of a flower in the scene*/
    const short MIN_FLOWER_HEIGHT = 150;

    /*The maximum height of a flower in the scene*/
    const short MAX_FLOWER_HEIGHT = 200;

    /*The angle of the falling bird */
    const qreal FREE_FALL_ANGLE = 90;

    /*The height that the bird will fall down after a certain period of time*/
    const qreal FREE_FALL_DIST= 30;

    /*The height that the bird will fly up after a key-press*/
    const qreal FLY_UP_DIST= 60;

    /*The Background Image Object*/
    QImage bgImage;

    /*The Upward Flower Image Object*/
    QImage upFlowerIm;

    /*The Downward Flower Image Object*/
    QImage downFlowerIm;

    /*This object helps to create flowers in the scene*/
    QGraphicsPixmapItem *flower;

    /*A vetors of all available flowers in the scene*/
    QVector<QGraphicsPixmapItem *> flowers;

    /*This object is used for controlling the flap of the bird*/
    QMovie *birdMovie;

    /*This graphics proxy object is used for managing the bird in the main scene*/
    QGraphicsProxyWidget *bird = NULL;

    /*Check if the bird is in the free-fall mode*/
    bool isFreeFall;

    /*Check if the bird is in the fly-up mode*/
    bool isFlyUp;

    /*The current vertical position of the bird*/
    qreal bXPos;

public:

    /**
     * The main constructor is uesed for initating all components in this scene
     */
    MainScene(QObject *parent = 0);

protected:
    /**
     * Overriding function from QGraphicsScene
     * This function will draw the background being one of three layers of the scene
     * @brief drawBackground
     * @param painter
     * @param rect
     */
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    /*Generate a scale for the height of a flower in a reasonable range*/
    short getHeightScale();

    /*Update lists of flowers for processing theirs movements*/
    void addNewFlower(QGraphicsPixmapItem *flower);

    /*Deleting the flower that passed the scence*/
    void deletePFlower(QGraphicsPixmapItem *flower);

    /*Creating a bird and putting it on the main scene*/
    void createABird(const QSize& birdSize);

    /*Check if the bird has just passed a column of flowers*/
    void updateScore(QGraphicsPixmapItem *flower);

signals:

public slots:

public:
    /*Add moving flowers to the scene*/
    void createFlowers();

    /*Move flowers to the scene*/
    void moveFlowers();

    /*Locate the bird to start the game*/
    void play();

    /*Apply the gravity on the bird*/
    void freeFallBird();

    /*User controls the bird to fly up*/
    void flyUpBird();

    /*Check for the collision between the bird and a flower*/
    bool hasCollision();

    /*This function will notify the main window in case of a collision happens*/
    void checkForCollision();

    /*Clean-up all components to prepare for a new game*/
    void restartScene();
};

#endif // MAINSCENE_H
