#include "startmenu.h"
#include "ui_startmenu.h"
#include "uicontroller.h"

StartMenu::StartMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);

    //Fill the items of the difficulty ComboBox
    ui->difficultyComboBox->addItem("Easy");
    ui->difficultyComboBox->addItem("Medium");
    ui->difficultyComboBox->addItem("Hard");
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_startButton_clicked()
{
    if(ui->difficultyComboBox->currentText().compare("Easy")){
        //low speed
        //uicontroller->changeDifficulty(12, 170);
    }
    else if (ui->difficultyComboBox->currentText().compare("Medium")){
        //medium speed
        //uicontroller->changeDifficulty(15, 200);
    }
    else if (ui->difficultyComboBox->currentText().compare("Hard")){
        //high speed
        //uicontroller->changeDifficulty(18, 250);
    }

    this->hide();

}
