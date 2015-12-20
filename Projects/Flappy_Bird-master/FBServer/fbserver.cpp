#include "fbserver.h"
#include "fbsocket.h"

/**
 * @brief FBServer::FBServer
 * @param parent
 */
FBServer::FBServer(QObject *parent)
    : QTcpServer(parent)
{

}

/**
 * @brief FBServer::incomingConnection
 * @param socketId
 */
void FBServer::incomingConnection(int socketId)
{
    FBSocket *socket = new FBSocket(this);
    socket->setSocketDescriptor(socketId);

}
