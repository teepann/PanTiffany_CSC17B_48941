#include "fbsocket.h"
#include <QDataStream>

/**
 * @brief FBSocket::FBSocket
 * @param parent
 */
FBSocket::FBSocket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

/**
 * @brief FBSocket::createConnection
 */
FBSocket::Connection FBSocket::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("209.129.8.2");
    db.setDatabaseName("48941");
    db.setUserName("48941");
    db.setPassword("48941cis17b");
    Connection connection;
    connection.db = db;
    if (!db.open()) {
        connection.connected = false;
        return connection;
    }
    connection.connected = true;

    return connection;
}



/**
 * @brief FBSocket::readClient
 */
void FBSocket::readClient()
{
    QDataStream in(this);

    QString name;

    QString score;

    in >> name >> score;

    //Saving to the SQL server - start
    Connection connection = createConnection();
    if ( connection.connected ){
        QSqlQuery query;
        query.exec("INSERT INTO FlappingBird (UserName, Score)"
                   "VALUES ('" + name + "','" + score +"')");
        connection.db.close();

    }
    //Saving to the SQL server - end

    close();
}

