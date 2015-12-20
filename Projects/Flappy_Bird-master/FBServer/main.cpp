
#include <QApplication>
#include <fbserver.h>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FBServer server;
    if (!server.listen(QHostAddress::Any, 6178)) {
        qDebug() << "Failed to bind to port";
        return 1;
    }

    QPushButton quitButton("Quit");
    quitButton.setWindowTitle("Flapping Bird Server");
    QObject::connect(&quitButton, SIGNAL(clicked()),
                     &a, SLOT(quit()));
    quitButton.setMinimumWidth(500);
    quitButton.setMinimumHeight(250);
    quitButton.show();

    return a.exec();
}
