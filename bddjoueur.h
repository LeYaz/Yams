#ifndef BDDJOUEUR_H
#define BDDJOUEUR_H

#include <QDialog>
#include <bdd.h>
#include <QMessageBox>

namespace Ui {
class BddJoueur;
}

class BddJoueur : public QDialog
{
    Q_OBJECT

public:
    explicit BddJoueur(QWidget *parent = 0);
    ~BddJoueur();
    void update();

private slots:
    void on_pushButton_clicked();

    void on_pushButtUpdate_clicked();

    void on_pushButtDelete_clicked();

    void on_pushButtLoad_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::BddJoueur *ui;
};

#endif // JOUEUR_H
