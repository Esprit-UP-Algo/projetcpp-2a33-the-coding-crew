
#include"connect.h"
Connection::Connection()
{

}
bool Connection::createconnect()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Maram");
db.setPassword("maram123");

if (db.open()) test=true;


 return test;
}
