#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>

namespace Ui {
class StartMenu;
}

class StartMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = 0);
    ~StartMenu();

private slots:
    /*This function starts the game when start is clicked*/
    void on_startButton_clicked();

private:
    Ui::StartMenu *ui;
};

#endif // STARTMENU_H
