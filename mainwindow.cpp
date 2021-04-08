#include "mainwindow.h"
#include "livraison.cpp"
#include "livraison.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablivraison->setModel(tmplivraison.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int prix=ui->le_prix->text().toInt();
    QString datelivraison=ui->le_datelivraison->text();
    QString adresselivraison=ui->le_datelivraison->text();

    livraison L(prix,datelivraison,adresselivraison);

    bool test=L.ajouter();

    if (test)
       {
        ui->tablivraison->setModel(tmplivraison.afficher());//refresh
        QMessageBox::information(nullptr ,QObject::tr("OK"),
                QObject::tr("Ajout effectué\n"
                            "Click OK to exit"),QMessageBox::Ok);
        }

    else
    {

        QMessageBox::critical(nullptr ,QObject::tr("Not OK"),
                QObject::tr("Ajout echoué\n"
                            "Click OK to exit"),QMessageBox::Ok);
    }

}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->le_id->text().toInt();
bool test=tmplivraison.supprimer(id);
if(test)
{ui->tablivraison->setModel(tmplivraison.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un livraison"),
                QObject::tr("livraison supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un livraison"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


