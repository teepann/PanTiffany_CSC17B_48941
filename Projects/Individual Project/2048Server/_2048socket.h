#ifndef _2048SOCKET_H
#define _2048SOCKET_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class _2048Socket : public QTcpSocket
{
private:

    /* A simple MySQL database connection*/
    typedef struct CONNECTION{
        QSqlDatabase db;
        bool connected;
    } Connection;


public:
    /**
     * @brief _2048Socket
     * @param parent
     */
    _2048Socket(QObject *parent = 0);

private:

    /* This function tries connecting to the RCC's MySQL database server*/
    Connection createConnection();


private slots:
    /**
     * @brief readClient
     */
    void readClient();
};

#endif // _2048SOCKET_H
