#ifndef FBHELPER_H
#define FBHELPER_H

#include <QTcpSocket>

/*The Flapping Bird Helper class*/
class FBHelper : public QObject
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
    FBHelper();

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

#endif // FBHELPER_H
