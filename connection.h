#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
public:
    Connection();
    bool createConnect();
    void closeConnection();

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
