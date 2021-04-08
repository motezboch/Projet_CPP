#include "livraison.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>


livraison::livraison()
{

datelivraison="";
adresselivraison="";
}
livraison::livraison(int prix, QString datelivraison, QString adresselivraison)
{
  this->prix=prix;
  this->datelivraison=datelivraison;
  this->adresselivraison=adresselivraison;
}
int livraison::get_id(){return id;}
int livraison::get_prix(){return  prix;}
QString livraison::get_datelivraison(){return datelivraison;}
QString livraison::get_adresselivraison(){return  adresselivraison;}

void setid(int);
void setprix(int);
void setdatelivraison(QString);
void setadresselivraison(QString);

bool livraison::ajouter()
{
QSqlQuery query;
QString res= QString::number(prix);
query.prepare("INSERT INTO etudiant (prix, datelivraison, adresselivraison) "
                    "VALUES (:res, :datelivraison, :adresselivraison)");
query.bindValue(":prix", res);
query.bindValue(":datelivraison", datelivraison);
query.bindValue(":adresselivraison", adresselivraison);

return    query.exec();
}

QSqlQueryModel * livraison::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("datelivraison"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresselivraison"));
    return model;
}

bool livraison::modifier(int prix,QString datelivraison,QString adresselivraison)
{

    QSqlQuery qry;


        qry.prepare("UPDATE livraison set prix=(?),datelivraison=(?),adresselivraison=(?)");

        qry.addBindValue(prix);
        qry.addBindValue(datelivraison);
        qry.addBindValue(adresselivraison);


   return  qry.exec();
}



bool livraison::supprimer(int idd)
{
QSqlQuery query;
QString res1= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}


QSqlQueryModel * livraison::trieID(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM livraison ORDER BY id ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datelivraison"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresselivraison"));

    return model;

}

QSqlQueryModel * livraison ::recherche (const QString &aux)

{

    QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from livraison where ((id || prix || datelivraison || adresselivraison) LIKE '%"+aux+"%')");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("datelivraison"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresselivraison"));



    return model;
}




