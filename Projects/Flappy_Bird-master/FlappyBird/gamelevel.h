#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <QString>

/**
 * This class is implemented in form of combination of singleton and type-safe enum design patterns.
 * It is used for managing the difficuty of a game
 * , and the difficulty is defined base on the bird size and the flower speed.
 * The class is simultaneously accessed by all UI components.
 * @brief The GameLevel class
 */
class GameLevel
{

public:

    /*The easy level object*/
    static const GameLevel EASY;

    /*The medium level object*/
    static const GameLevel MEDIUM;

    /*The hard level object*/
    static const GameLevel HARD;

private:

    /*The number of difficulties*/
    static const int NUMBER_OF_LEVEL = 3;

    /*The management array of all levels*/
    static const GameLevel levels[];

    /* The bird image scalars for easy, medium, and hard levels */
    static const float BIRD_PIC_SCALARS[];

    /* The flower speed in miliseconds for easy, medium, and hard levels */
    static const int FLOWER_SPEEDS[];

    /*The singleton object*/
    static GameLevel gLevel;

    /*The name of a difficulty level*/
    QString levelN;

    /*The id of a difficulty level*/
    int id;

    /*The constructor of the singleton object*/
    GameLevel(QString levelN = "", int id = 0);

public:

    /*Auto generated getters and setters*/
    QString getLevelN() const;
    static void setLevelN(const QString &value);

    int getId() const;
    static void setId(int value);

    /*The singleton design method*/
    static GameLevel getInstance();

    /*This function returns the bird picture scalar base on the current game difficulty*/
    static float getBirdPicScalar();

    /*This function returns the flower speed base on the current game difficulty*/
    static int getFlowerSpeed();
};

#endif // GAMELEVEL_H
