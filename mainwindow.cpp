#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parametregrille.hpp"

Joueur joueur[4];
Joueur g1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushValider_clicked()
{




///Recupère les valeur dans col libre 1ere partie
    for(int i=0; i<6; i++){
        int j=1; ///première colonne
        int px=31+100*i; /// calcul de la position en pixel de la case
        QString test=ui->tabGrille->itemAt(j,px)->text();
        g1.SetPointColLibre(i, test.toInt());
        //ui->tabGrille->itemAt(j,px)->setBackgroundColor(Qt::green);
        QString chiffre = QString::number(g1.GetPointColLibre(i));
        ui->tabGrille->itemAt(j,px)->setText(chiffre);///
    }

    //Recupère les valeur dans col libre 2eme partie
        for(int i=8; i<14; i++){
            int j=1; ///première colonne
            int px=31+100*i; /// calcul de la position en pixel de la case
            QString test=ui->tabGrille->itemAt(j,px)->text();
            g1.SetPointColLibre(i, test.toInt());
            //ui->tabGrille->itemAt(j,px)->setBackgroundColor(Qt::green);
            QString chiffre = QString::number(g1.GetPointColLibre(i));
            ui->tabGrille->itemAt(j,px)->setText(chiffre);///
        }


    g1.SetPointColLibreLigneBonus(); /// Calcul le Bonus de la colonne libre
    g1.SetPointcolLibreTotal(); ///Calcul le total de la colonne libre
    QString bonus =QString::number( g1.GetPointColLibreLigneBonus()); /// convertie le bonus(int) en string
    ui->tabGrille->itemAt(1,631)->setText(bonus); /// affiche le bonus col libre
    QString total =QString::number(g1.GetPointColLibre(7)); ///convertie le total(int) en string
    ui->tabGrille->itemAt(1,731)->setText(total); ///affiche le total col Libre
    g1.SetPointcolLibreTotalGeneral();
    QString totalg =QString::number(g1.GetPointColLibre(15));
    ui->tabGrille->itemAt(1,1431)->setText(totalg);

 ///recupère les valeurs dans  la col Montante

    for(int i=0; i<6; i++){
        int j=231;
        int px=31+100*i;
        QString test=ui->tabGrille->itemAt(j,px)->text();
        g1.SetPointColMontante(i, test.toInt());
    }

    g1.SetPointColMontanteLigneBonus();                            /// Calcul le Bonus de la colonne Montante
    g1.SetPointcolMontanteTotal();                                 ///Calcul le total de la colonne Montante
    bonus =QString::number( g1.GetPointColMontanteLigneBonus());   /// convertie le bonus(int) en string
    ui->tabGrille->itemAt(231,631)->setText(bonus);                /// affiche le bonus col Montante
    total =QString::number(g1.GetPointColMontante(7));             ///convertie le total(int) en string
    ui->tabGrille->itemAt(231,731)->setText(total);                ///affiche le total col Montante


   update();



}
