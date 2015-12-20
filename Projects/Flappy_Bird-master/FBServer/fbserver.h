#ifndef FBSERVER_H
#define FBSERVER_H

#include <QObject>
#include <QTcpServer>

class FBServer : public QTcpServer
{
    Q_OBJECT

public:
    /**
     * @brief FBServer
     * @param parent
     */
    FBServer(QObject *parent = 0);

private:
    /**
     * @brief incomingConnection
     * @param socketId
     */
    void incomingConnection(int socketId);

signals:

public slots:
};

#endif // FBSERVER_H
