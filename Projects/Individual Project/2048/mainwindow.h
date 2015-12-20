#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QActionGroup>
#include "Tile.h"
#include "helper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createboard();
    void keyPressEvent(QKeyEvent *event);
    void startGame();
    void randomtile();
    bool isFull();
    bool movepossible();
    void exchange(Tile *Box1,Tile *Box2);
    void emptytileMoveLft();
    void emptytileMoveDown();
    void emptytileMoveRight();
    void emptytileMoveUp();
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();
    void endGame(int ch);
    void backupGrid();

private:
    Ui::MainWindow *ui;
    Tile* tile[4][4];
    int btile[4][4];
    int score;
    int bscore;

    QPushButton* resetb;
    QPushButton* exit;
    QWidget* endgame;
    QVBoxLayout *layout;
    QLabel* word;
    QLabel* scoreLabel;
    QLabel* nameLabel;
    QLineEdit* name;

    QWidget* helpscreen;
    QVBoxLayout* hlayout;
    QLabel* hnameLabel;
    QPushButton* okb;
    helper* gamehelper;

signals:
     void changed(int score);

public slots:
     void reset();
     void quits();
     void undo();
     void help();
     void addInfo();
private slots:
     void on_actionUndo_triggered();
     void on_actionHelp_triggered();
     void on_actionNew_Game_triggered();
};

#endif // MAINWINDOW_H
