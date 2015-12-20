#ifndef HELPER_H
#define HELPER_H

#include <QTcpSocket>

class helper : public QObject
{
    Q_OBJECT

private:

    /**
     * @brief tcpSocket
     */
    QTcpSocket* tcpSocket;

    /**
     * @brief userName
     */
    QString userName;

    /**
     * @brief score
     */
    QString score;

public:
    /*The default constructor*/
    helper();

    /* Save a record the database*/
    void save(QString userName, int score);

private slots:

    /**
     * @brief sendData
     */
    void sendData();

    /**
     * @brief processError
     */
    void processError();
};

#endif // HELPER_H
