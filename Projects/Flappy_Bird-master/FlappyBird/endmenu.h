#ifndef ENDMENU_H
#define ENDMENU_H


#include <QFile>
#include <QTextStream>
#include <QDialog>

namespace Ui {
class EndMenu;
}

class EndGMenu : public QDialog
{
    Q_OBJECT

public:
    explicit EndGMenu(QWidget *parent = 0);
    ~EndGMenu();
    void addPlayerInfo();

private:
    Ui::EndMenu *ui;
};

#endif // ENDMENU_H
