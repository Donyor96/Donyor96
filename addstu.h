#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addStu;
}

class addStu : public QDialog
{
    Q_OBJECT

public:
    explicit addStu(QWidget *parent = nullptr);
    ~addStu();
    void writeinforTofile(QString cnt);
    void clearUserinfo();

private slots:
    void on_btn_OK_clicked();



private:
    Ui::addStu *ui;
};

#endif // ADDSTU_H
