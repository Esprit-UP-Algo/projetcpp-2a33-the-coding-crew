#ifndef CONNECT_H
#define CONNECT_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//DESTDIR = ../bin
class Connection
{
public:
    Connection();
    bool createconnect();
};


#endif // CONNECT_H
