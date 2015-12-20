#include "_2048socket.h"
#include <QDataStream>

/**
 * @brief _2048Socket::_2048Socket
 * @param parent
 */
_2048Socket::_2048Socket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

/**
 * @brief _2048Socket::createConnection
 */
_2048Socket::Connection _2048Socket::createConnection()
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
 * @brief _2048Socket::readClient
 */
void _2048Socket::readClient()
{
    QDataStream in(this);

    QString name;

    QString score;

    in >> name >> score;

    //Saving to the SQL server - start
    Connection connection = createConnection();
    if ( connection.connected ){
        QSqlQuery query;
        query.exec("INSERT INTO Game2048 (UserName, Score)"
                   "VALUES ('" + name + "','" + score +"')");
        connection.db.close();

    }
    //Saving to the SQL server - end

    close();
}
