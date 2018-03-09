#include "pageacceuil.hpp"
#include "ui_pageacceuil.h"
#include "mainwindow.h"
#include "pagenouvellepartie.h"
#include "bdd.h"

PageAcceuil::PageAcceuil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAcceuil)
{
    ui->setupUi(this);
    
}

void PageAcceuil::SetOpenNewPartie(){
    _openNewPartie=true;
}
bool PageAcceuil::GetOpenNewPartie(){
    return _openNewPartie;
}
PageAcceuil::~PageAcceuil()
{
    delete ui;
}


void PageAcceuil::on_buttonNewGame_clicked()
{


   // MainWindow *main = new MainWindow(this);
   // main->show();

    Bdd *bdd = new Bdd(this);
    bdd->show();




   // SetOpenNewPartie();
    update();
    this->hide();
}

void PageAcceuil::on_buttonLoadGame_clicked()
{
    PageNouvellePartie *p1 = new PageNouvellePartie(this);
    p1->showMaximized();
    ui->buttonLoadGame->hide();
    ui->buttonNewGame->hide();





}
