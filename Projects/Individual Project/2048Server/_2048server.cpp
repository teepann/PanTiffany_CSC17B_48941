#include "_2048server.h"

/**
 * @brief _2048Server::_2048Server
 * @param parent
 */
_2048Server::_2048Server(QObject *parent)
    : QTcpServer(parent)
{

}

/**
 * @brief _2048Server::incomingConnection
 * @param socketId
 */
void _2048Server::incomingConnection(int socketId)
{
    _2048Server *socket = new _2048Server(this);
    socket->setSocketDescriptor(socketId);
}
