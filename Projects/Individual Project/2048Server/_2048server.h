#ifndef _2048SERVER_H
#define _2048SERVER_H

#include <QObject>
#include <QTcpServer>

class _2048Server: public QTcpServer
{
public:
    /**
     * @brief _2048Server
     * @param parent
     */
    _2048Server(QObject *parent = 0);

private:
    /**
     * @brief incomingConnection
     * @param socketId
     */
    void incomingConnection(int socketId);
};
#endif // _2048SERVER_H
