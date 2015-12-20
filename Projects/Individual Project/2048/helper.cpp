#include "helper.h"
#include <QtNetwork>


/**
 * @brief helper::helper
 */
helper::helper()
{
    tcpSocket = new QTcpSocket();

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendData()));
    connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(processError()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(processError()));

}

/**
 * @brief helper::save
 * @param userName
 * @param score
 * @return
 */
void helper::save(QString userName, int score)
{

    this->userName = userName;
    this->score = QString::number(score);
    tcpSocket->connectToHost(QHostAddress::LocalHost, 2048);

}

/**
 * @brief helper::sendData
 */
void helper::sendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out << userName << score;

    tcpSocket->write(block);
    tcpSocket->close();

}

/**
 * @brief helper::processError
 */
void helper::processError()
{
    tcpSocket->close();
}

