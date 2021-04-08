#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class livraison
{
public:
    livraison();
    livraison(int,QString,QString);
    int get_id();
    int get_prix();
    QString get_datelivraison();
    QString get_adresselivraison();


    void setprix(int);
    void setdatelivraison(QString);
    void setadresselivraison(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int,QString,QString);
    bool supprimer(int);
    QSqlQueryModel * recherche (const QString &aux);
    QSqlQueryModel * trieID();

private:
    QString datelivraison,adresselivraison;
    int prix,id;

};

#endif // LIVRAISON_H


