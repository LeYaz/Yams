#include "pagenouvellepartie.h"
#include "ui_pagenouvellepartie.h"
#include "parametregrille.hpp"
#include "mainwindow.h"



PageNouvellePartie::PageNouvellePartie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageNouvellePartie)
{
    ui->setupUi(this);
}

PageNouvellePartie::~PageNouvellePartie()
{
    delete ui;
}

void PageNouvellePartie::on_boxNbrJoueur_valueChanged(int arg1)
{




    switch(arg1){

    case 0 :
        ui->lineEditNomJoueur1->hide();
        ui->labelNomJoueur1->hide();
        ui->lineEditNomJoueur2->hide();
        ui->lineEditNomJoueur3->hide();
        ui->lineEditNomJoueur4->hide();
        ui->labelNomJoueur2->hide();
        ui->labelNomJoueur3->hide();
        ui->labelNomJoueur4->hide();
        break;

    case 1 :
        ui->lineEditNomJoueur1->show();
        ui->labelNomJoueur1->show();

        ui->lineEditNomJoueur2->hide();
        ui->labelNomJoueur2->hide();
        ui->lineEditNomJoueur3->hide();
        ui->lineEditNomJoueur4->hide();
        ui->labelNomJoueur3->hide();
        ui->labelNomJoueur4->hide();
        break;

    case 2 :
        ui->lineEditNomJoueur1->show();
        ui->labelNomJoueur1->show();
        ui->lineEditNomJoueur2->show();
        ui->labelNomJoueur2->show();


        ui->lineEditNomJoueur3->hide();
        ui->lineEditNomJoueur4->hide();
        ui->labelNomJoueur3->hide();
        ui->labelNomJoueur4->hide();
        break;

    case 3 :
        ui->lineEditNomJoueur1->show();
        ui->labelNomJoueur1->show();
        ui->lineEditNomJoueur2->show();
        ui->labelNomJoueur2->show();
        ui->lineEditNomJoueur3->show();
        ui->labelNomJoueur3->show();

        ui->lineEditNomJoueur4->hide();
        ui->labelNomJoueur4->hide();
        break;


    case 4 :
        ui->lineEditNomJoueur1->show();
        ui->labelNomJoueur1->show();
        ui->lineEditNomJoueur2->show();
        ui->labelNomJoueur2->show();
        ui->lineEditNomJoueur3->show();
        ui->labelNomJoueur3->show();
        ui->lineEditNomJoueur4->show();
        ui->labelNomJoueur4->show();
        break;

    default :
        ui->lineEditNomJoueur1->hide();
        ui->labelNomJoueur1->hide();
        ui->lineEditNomJoueur2->hide();
        ui->lineEditNomJoueur3->hide();
        ui->lineEditNomJoueur4->hide();
        ui->labelNomJoueur2->hide();
        ui->labelNomJoueur3->hide();
        ui->labelNomJoueur4->hide();

    }


}

void PageNouvellePartie::on_buttonValiderNbrJoueur_clicked()
{


    //int nbrJ = ui->boxNbrJoueur->value();




   // ParametreGrille._nbrjoueur=nbrJ;







}

void PageNouvellePartie::on_pushButton_clicked()
{
    QString nomJ1, nomJ2, nomJ3, nomJ4;

    bool col1, col2, col3, col4;

    nomJ1=ui->lineEditNomJoueur1->text();
    nomJ2=ui->lineEditNomJoueur2->text();
    nomJ3=ui->lineEditNomJoueur3->text();
    nomJ4=ui->lineEditNomJoueur4->text();

    col1=ui->col1->checkState();
    col2=ui->col2->checkState();
    col3=ui->col3->checkState();
    col4=ui->col4->checkState();




    MainWindow *m = new MainWindow(this);

    m->show();


}
