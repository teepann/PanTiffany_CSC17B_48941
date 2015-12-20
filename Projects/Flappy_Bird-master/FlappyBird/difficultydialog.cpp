#include "difficultydialog.h"
#include "ui_difficultydialog.h"

/**
 * @brief DifficultyDialog::DifficultyDialog
 * @param parent
 */
DifficultyDialog::DifficultyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifficultyDialog)
{
    ui->setupUi(this);

    ui->dComboBox->addItem(GameLevel::EASY.getLevelN());
    ui->dComboBox->addItem(GameLevel::MEDIUM.getLevelN());
    ui->dComboBox->addItem(GameLevel::HARD.getLevelN());
}

/**
 * @brief DifficultyDialog::~DifficultyDialog
 */
DifficultyDialog::~DifficultyDialog()
{
    delete ui;
}

/**
 * @brief DifficultyDialog::closeEvent
 */
void DifficultyDialog::closeEvent(QCloseEvent *)
{
    exit(EXIT_SUCCESS);
}


/**
 * @brief DifficultyDialog::on_startButton_clicked
 */
void DifficultyDialog::on_startButton_clicked()
{
    GameLevel::setLevelN(ui->dComboBox->currentText());
    emit startGame();
}
