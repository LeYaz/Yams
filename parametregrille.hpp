#ifndef PARAMETREGRILLE_H
#define PARAMETREGRILLE_H
#include<iostream>
#include "parametregrille.hpp"
#include<QString>
#include<QTableWidget>

using namespace std;

///classe permettant de connaitre les éléments utilisées dans la grille

class ParametreGrille
{

    ///Définit le nombre de grille a créer

  public : int _nbrjoueur;

    ///Activer/Désactiver les colones

    bool _col[4];




public:

    ///Méthodes nombre de joueurs (nbr de grille a crée)

    int GetNbrJoueur()const{return _nbrjoueur;}
    void SetNbrJoueur(int nbr){_nbrjoueur=nbr; return;}


    ///Méthodes colonnes

    bool GetCol(int i)const {return _col[i];}
    void SetCol(int i, bool col){_col[i]=col; return;}

    bool GetColLibre()const {return _col[0];} /// Retourne l'état de la colonne
    void SetColLibre(bool libre){_col[0]=libre; return;} ///Récupère l'état de la colonne

    bool GetColHaut()const {return _col[1];}
    void SetColHaut(bool haut){_col[1]=haut; return;}

    bool GetColBas()const {return _col[2];}
    void SetColBas(bool bas){_col[2]=bas; return;}

    bool GetColSec()const {return _col[3];}
    void SetColSec(bool sec){_col[3]=sec; return;}










    ParametreGrille();
};



///classe permettant de compter les points de la grille et de valider les saisie




class PointGrille :public ParametreGrille
{

    ///entier contenant les points de la colonne libre pour chacune des lignes

    int _colLibre[16];

    int _colMontante[16];

    int _colDescendante[16];

    int _colSec[16];






public:

    /// GETer et SETer pour la colonnes LIBRE

    int GetPointColLibre(int i)const{return _colLibre[i];}
   /* void SetPointColLibre(int i, int point){
        if((point>0)&&point<31){
            _colLibre[i]=point;
        }else _colLibre[i]=0;
        return;}
*/
    void SetPointColLibre(int i, int point){
        switch(i){
        case 0:
            if((point>0)&&(point<6)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;

        case 1 :
            if((point>0)&&(point<11)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;

        case 2 :
            if((point>0)&&(point<16)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;

        case 3 :
            if((point>0)&&(point<21)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;

        case 4 :
            if((point>0)&&(point<26)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;


        case 5 :
            if((point>0)&&(point<31)){
                _colLibre[i]=point;
            }else _colLibre[i]=0;
            break;

        default :
            if((point>0)&&(point<51)){
                _colLibre[i]=point;

        }else _colLibre[i]=0;
        break;
    }
    }

    int GetPointColLibreLigne1()const{return _colLibre[0];}
    void SetPointColLibreLigne1(int pointl1){_colLibre[0]=pointl1; return;}

    int GetPointColLibreLigne2()const{return _colLibre[1];}
    void SetPointColLibreLigne2(int pointl2){_colLibre[1]=pointl2; return;}

    int GetPointColLibreLigne3()const{return _colLibre[2];}
    void SetPointColLibreLigne3(int pointl3){_colLibre[2]=pointl3; return;}

    int GetPointColLibreLigne4()const{return _colLibre[3];}
    void SetPointColLibreLigne4(int pointl4){_colLibre[3]=pointl4; return;}

    int GetPointColLibreLigne5()const{return _colLibre[4];}
    void SetPointColLibreLigne5(int pointl5){_colLibre[4]=pointl5; return;}

    int GetPointColLibreLigne6()const{return _colLibre[5];}
    void SetPointColLibreLigne6(int pointl6){_colLibre[5]=pointl6; return;}

    int GetPointColLibreLigneBonus()const{return _colLibre[6];}
    void SetPointColLibreLigneBonus(){
        int somme=0;
        for(int i=0;i<6;i++){
            somme+=_colLibre[i];
        }
        if(somme>=63){_colLibre[6]=35;}else _colLibre[6]=0;
    }

    int GetPointColLibreTotal()const{return _colLibre[7];}
    void SetPointcolLibreTotal(){
        int somme=0;
        for(int i=0;i<7;i++){
            somme+=_colLibre[i];

        }
        _colLibre[7]=somme;
    }

   int GetPointColLibreLigneChance()const{return _colLibre[8];}
    void SetPointColLibreLigneChance(int brelan){_colLibre[8]=brelan; return;}

    int GetPointColLibreLigneBrelan()const{return _colLibre[9];}
    void SetPointColLibreLigneBrelan(int brelan){_colLibre[9]=brelan; return;}

    int GetPointColLibreLignePteSuite()const{return _colLibre[10];}
    void SetPointColLibreLignePteSuite(int suite){_colLibre[10]=suite; return;}

    int GetPointColLibreLigneGdeSuite()const{return _colLibre[11];}
    void SetPointColLibreLigneGdeSuite(int gde){_colLibre[11]=gde; return;}

    int GetPointColLibreLigneFull()const{return _colLibre[12];}
    void SetPointColLibreLigneFull(int gde){_colLibre[12]=gde; return;}

    int GetPointColLibreLigneCarre()const{return _colLibre[13];}
    void SetPointColLibreLigneCarre(int gde){_colLibre[13]=gde; return;}

    int GetPointColLibreLigneYam()const{return _colLibre[14];}
    void SetPointColLibreLigneYam(int gde){_colLibre[14]=gde; return;}

    int GetPointColLibreTotalGeneral()const{return _colLibre[15];}
    void SetPointcolLibreTotalGeneral(){
        int somme=0;
        for(int i=7;i<15;i++){
            somme+=_colLibre[i];

        }
        _colLibre[15]=somme;
    }



    ///GETer et SETer pour la colonnes MONTANTE

    int GetPointColMontante(int i)const{return _colMontante[i];}
    void SetPointColMontante(int i, int point){

      if(i==0){
        if((point>0)&&point<31){
            _colMontante[i]=point;
        }else _colMontante[i]=0;}
      else {
            int n = GetPointColMontante(i-1);
            if(n=!0){
                if((point>0)&&point<31){
                    _colMontante[i]=point;
                }else _colMontante[i]=0;

            }else _colMontante[i]=0;

        }
        return;}

    int GetPointColMontanteLigneBonus()const{return _colMontante[6];}
    void SetPointColMontanteLigneBonus(){
        int somme=0;
        for(int i=0;i<6;i++){
            somme+=_colMontante[i];
        }
        if(somme>=63){_colMontante[6]=35;}else _colMontante[6]=0;
    }

    int GetPointColMontanteTotal()const{return _colMontante[7];}
    void SetPointcolMontanteTotal(){
        int somme=0;
        for(int i=0;i<7;i++){
            somme+=_colMontante[i];

        }
        _colMontante[7]=somme;
    }


    PointGrille();

};



class Joueur : public PointGrille
{
    QString _nom;
    int _positionjoueur;



public :



    int GetPositionJoueur()const{return _positionjoueur;}
    void SetPositionJoueur(int pos){_positionjoueur=pos; return;}

    QString GetNomJoueur()const{return _nom;}
    void SetNomJoueur(QString pos){_nom=pos; return;}



    Joueur();

};

#endif // PARAMETREGRILLE_H



