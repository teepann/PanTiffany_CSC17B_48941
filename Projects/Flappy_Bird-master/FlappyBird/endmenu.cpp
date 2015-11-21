#include "endmenu.h"
#include "ui_endmenu.h"

EndGMenu::EndGMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndMenu)
{
    ui->setupUi(this);
}

EndGMenu::~EndGMenu()
{
    delete ui;
}

void EndGMenu::addPlayerInfo()
{
    QFile players("players.txt");
    if(!players.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&players);
    out << ui->nameLineEdit->text();
    players.close();
    //add score?
    //read file for highest score
    //close file?
}
