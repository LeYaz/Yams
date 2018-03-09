#ifndef BDD_H
#define BDD_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class Bdd;
}

class Bdd : public QMainWindow
{
    Q_OBJECT

public:
        QSqlDatabase mydb;
        void connClose()
        {
            mydb.close();
            mydb.removeDatabase(QSqlDatabase::defaultConnection);
        }

        bool connOpen()
        {
            mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("../yams.db");

            if (!mydb.open())
            {
                qDebug()<<("Failed to open the database");
                return false;
            }
            else
            {
                qDebug()<<("Connected...");
                return true;
            }
        }

public:
    explicit Bdd(QWidget *parent = 0);
    ~Bdd();

private slots:

   // void on_pushButtLog_clicked();

    void on_pushButtAddP_clicked();

private:
    Ui::Bdd *ui;
};

#endif // MAINWINDOW_H
