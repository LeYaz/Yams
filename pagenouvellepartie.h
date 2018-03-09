#ifndef PAGENOUVELLEPARTIE_H
#define PAGENOUVELLEPARTIE_H

#include <QWidget>

namespace Ui {
class PageNouvellePartie;
}

class PageNouvellePartie : public QWidget
{
    Q_OBJECT

public:
    explicit PageNouvellePartie(QWidget *parent = 0);
    ~PageNouvellePartie();

private slots:
    void on_boxNbrJoueur_valueChanged(int arg1);

    void on_buttonValiderNbrJoueur_clicked();

    void on_pushButton_clicked();

private:
    Ui::PageNouvellePartie *ui;
};

#endif // PAGENOUVELLEPARTIE_H
