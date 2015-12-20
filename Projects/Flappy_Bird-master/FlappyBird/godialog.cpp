#include "godialog.h"
#include "ui_godialog.h"

/**
 * @brief GODialog::GODialog
 * @param parent
 */
GODialog::GODialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GODialog)
{
    ui->setupUi(this);

    fbHelper = new FBHelper();
}

/**
 * @brief GODialog::~GODialog
 */
GODialog::~GODialog()
{
    delete ui;
}

/**
 * @brief GODialog::show
 * @param score
 */
void GODialog::populateUI(int score)
{
    ui->scoreDisplay->display(score);
    show();
}

/**
 * @brief GODialog::closeEvent
 */
void GODialog::closeEvent(QCloseEvent *)
{
    exit(EXIT_SUCCESS);
}

/**
 * @brief GODialog::on_quitButton_clicked
 */
void GODialog::on_quitButton_clicked()
{
    exit(0);
}

/**
 * @brief GODialog::on_restartButton_clicked
 */
void GODialog::on_restartButton_clicked()
{
    hide();
    emit restart();
}

/**
 * @brief GODialog::on_sRestartButton_clicked
 */
void GODialog::on_sRestartButton_clicked()
{
    hide();

    fbHelper->save(ui->nameLineEdit->text(),ui->scoreDisplay->value());

    emit restart();
}
