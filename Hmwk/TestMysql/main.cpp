#include <QApplication>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
struct Connection{
    QSqlDatabase db;
    bool connected;
};
Connection createConnection();
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Connection connection = createConnection();
    if ( !connection.connected ){
        qDebug() << "Not connected!";
        return 1;
    }
    else{
        qDebug() << "Connected!";
        QSqlQuery query;
        query.exec("INSERT INTO FlappingBird (UserName, Score)"
                   "VALUES ('Tiffany','10')");
        connection.db.close();
        return 0;
    }
    return a.exec();
}
Connection createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("209.129.8.2");
    db.setDatabaseName("48941");
    db.setUserName("48941");
    db.setPassword("48941cis17b");
    Connection connection;
    connection.db = db;
    if (!db.open()) {
        qDebug() << "Database error occurred";
        connection.connected = false;
        return connection;
    }
    connection.connected = true;

    return connection;
}
