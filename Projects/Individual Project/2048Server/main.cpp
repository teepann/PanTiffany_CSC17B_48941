
#include <QApplication>
#include "_2048server.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _2048Server server;
    if (!server.listen(QHostAddress::Any, 2048)) {
        qDebug() << "Failed to bind to port";
        return 1;
    }

    QPushButton quitButton("Quit");
    quitButton.setWindowTitle("Game2048 Server");
    QObject::connect(&quitButton, SIGNAL(clicked()),
                     &a, SLOT(quit()));
    quitButton.setMinimumWidth(300);
    quitButton.setMinimumHeight(200);
    quitButton.show();

    return a.exec();
}
