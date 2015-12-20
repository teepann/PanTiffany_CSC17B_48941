#include "fbhelper.h"
#include <QtNetwork>


/**
 * @brief FBHelper::FBHelper
 */
FBHelper::FBHelper()
{
    tcpSocket = new QTcpSocket();

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sendData()));
    connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(processError()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(processError()));

}

/**
 * @brief FBHelper::save
 * @param userName
 * @param score
 * @return
 */
void FBHelper::save(QString userName, int score)
{

    this->userName = userName;
    this->score = QString::number(score);
    tcpSocket->connectToHost(QHostAddress::LocalHost, 6178);

}

/**
 * @brief FBHelper::sendData
 */
void FBHelper::sendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out << userName << score;

    tcpSocket->write(block);
    tcpSocket->close();

}

/**
 * @brief FBHelper::processError
 */
void FBHelper::processError()
{
    tcpSocket->close();
}

