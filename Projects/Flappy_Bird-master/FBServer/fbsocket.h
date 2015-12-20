#ifndef FBSOCKET_H
#define FBSOCKET_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class FBSocket : public QTcpSocket
{
    Q_OBJECT

private:

    /* A simple MySQL database connection*/
    typedef struct CONNECTION{
        QSqlDatabase db;
        bool connected;
    } Connection;


public:
    /**
     * @brief FBSocket
     * @param parent
     */
    FBSocket(QObject *parent = 0);

private:

    /* This function tries connecting to the RCC's MySQL database server*/
    Connection createConnection();


private slots:
    /**
     * @brief readClient
     */
    void readClient();

signals:

public slots:
};

#endif // FBSOCKET_H
