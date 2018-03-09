#ifndef PAGEACCEUIL_HPP
#define PAGEACCEUIL_HPP

#include <QWidget>

namespace Ui {
class PageAcceuil;
}

class PageAcceuil : public QWidget
{
    Q_OBJECT
    bool _openNewPartie=false;
    bool _openLoadPartie=false;

public :
    void SetOpenNewPartie();
    bool GetOpenNewPartie();

public:
    explicit PageAcceuil(QWidget *parent = 0);
    ~PageAcceuil();

private slots:
    void on_buttonNewGame_clicked();

    void on_buttonLoadGame_clicked();

private:
    Ui::PageAcceuil *ui;
};

#endif // PAGEACCEUIL_HPP
