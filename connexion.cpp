#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");
db.setUserName("medjalel");
db.setPassword("medjalel2001");
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
