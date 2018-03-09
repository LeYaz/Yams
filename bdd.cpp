#include "bdd.h"
#include "ui_bdd.h"
#include <QMessageBox>
#include <bddjoueur.h>

Bdd::Bdd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bdd)
{
    ui->setupUi(this);

    if (!connOpen())
    {
        ui->label->setText("Failed to open the database");
    }
    else
    {
        ui->label->setText("Connected...");
    }
}

Bdd::~Bdd()
{
    delete ui;
}

/*void MainWindow::on_pushButtLog_clicked()
{

    QString nom, mp;

    nom = ui->lineEditNom->text();
    mp = ui->lineEditMp->text();

    if(!connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from connexion where nom = '"+ nom +"' and motp = '"+ mp +"'  ");

    //qry.prepare("insert into joueur (id,name,pseudo) values ('"+id+"','"+prenom+"','"+pseudo+"')");

    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
            count++;

        if (count==1)
        {
            ui->label->setText("nom et mp correct :)");
            connClose();
            this->hide();
            Joueur affiche;
            affiche.setModal(true);
            affiche.exec();

        }
        if (count>1) ui->label->setText("duplicata nom ou mp ");
        if (count<1) ui->label->setText("nom et mp non correct !");
    }
    else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}*/

void Bdd::on_pushButtAddP_clicked()
{
    connClose();
    this->hide();
    BddJoueur affiche;
    affiche.setModal(true);
    affiche.exec();
}
