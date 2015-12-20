#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include <QDialog>
#include <gamelevel.h>

namespace Ui {
class DifficultyDialog;
}

class DifficultyDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::DifficultyDialog *ui;

public:
    //The main constructor
    explicit DifficultyDialog(QWidget *parent = 0);

    //The main destructor
    ~DifficultyDialog();

protected:

    //Handling the default close button of this dialog
    virtual void closeEvent(QCloseEvent*);

signals:
    //The start-game signal
    void startGame();

private slots:
    //Start button handler
    void on_startButton_clicked();


};

#endif // DIFFICULTYDIALOG_H
