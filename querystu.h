#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class queryStu;
}

class queryStu : public QDialog
{
    Q_OBJECT

public:
    explicit queryStu(QWidget *parent = nullptr);
    ~queryStu();
    int readfromfile();
    void doQuery(int index,QString cnt);
    void display(int row,QStringList list);
private slots:
    void on_pushButton_search_clicked();

private:
    Ui::queryStu *ui;
    QList<QString> stu_lines;
    QStandardItemModel *model;
};

#endif // QUERYSTU_H
