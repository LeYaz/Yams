#include "bddjoueur.h"
#include "ui_bddjoueur.h"

BddJoueur::BddJoueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BddJoueur)
{
    ui->setupUi(this);
        Bdd conn;

    if (!conn.connOpen())
    {
        ui->label->setText("Failed to open the database");
    }
    else
    {
        ui->label->setText("Connected...");
    }
}

BddJoueur::~BddJoueur()
{
    delete ui;
}

void BddJoueur::update()
{
    Bdd conn;
    QSqlQueryModel * modal= new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Prenom,Nom,Score from joueur");
    qry->exec();

    modal->setQuery(* qry);
    ui->tableView->setModel(modal);
    ui->listView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void BddJoueur::on_pushButton_clicked()
{
    Bdd conn;
    QString id, nom, prenom, score;

    id = ui->lineEditId->text();
    nom = ui->lineEditNom->text();
    prenom = ui->lineEditPrenom->text();
    score = ui->lineEditScore->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into joueur (joueurId,Nom,Prenom,Score) values ('"+id+"','"+nom+"','"+prenom+"','"+ score +"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("bdd modifier"));
        conn.connClose();
    }else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}

void BddJoueur::on_pushButtUpdate_clicked()
{
    Bdd conn;
    QString id, nom, prenom, score;

    id = ui->lineEditId->text();
    nom = ui->lineEditNom->text();
    prenom = ui->lineEditPrenom->text();
    score = ui->lineEditScore->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update joueur set joueurId = '"+id+"', Nom = '"+nom+"', Prenom = '"+prenom+"', Score = '"+ score +"' where joueurId = '"+id+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Mise a jour"));
        conn.connClose();
    }else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}

void BddJoueur::on_pushButtDelete_clicked()
{
    Bdd conn;
    QString id, nom, prenom, score;

    id = ui->lineEditId->text();
    nom = ui->lineEditNom->text();
    prenom = ui->lineEditPrenom->text();
    score = ui->lineEditScore->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from joueur where joueurId = '"+id+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Supprimer"));
        conn.connClose();
    }else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}

void BddJoueur::on_pushButtLoad_clicked()
{
    Bdd conn;
    QSqlQueryModel * modal= new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Prenom,Nom,Score from joueur");
    qry->exec();

    modal->setQuery(* qry);
    ui->tableView->setModel(modal);
    ui->listView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void BddJoueur::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString prenom = ui->comboBox->currentText();

   Bdd conn;

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from joueur where Prenom = '"+prenom+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEditId->setText(qry.value(0).toString());
            ui->lineEditNom->setText(qry.value(1).toString());
            ui->lineEditPrenom->setText(qry.value(2).toString());
            ui->lineEditScore->setText(qry.value(3).toString());
        }
        conn.connClose();
    }else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}

void BddJoueur::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    Bdd conn;

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the Database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from joueur where joueurId = '"+val+"' or Nom = '"+val+"' or Prenom = '"+val+"' or Score = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEditId->setText(qry.value(0).toString());
            ui->lineEditNom->setText(qry.value(1).toString());
            ui->lineEditPrenom->setText(qry.value(2).toString());
            ui->lineEditScore->setText(qry.value(3).toString());
        }
        conn.connClose();
    }else
    {
        QMessageBox::critical(this,tr("Error:"),qry.lastError().text());
    }
}
