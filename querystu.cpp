#include "querystu.h"
#include "ui_querystu.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
queryStu::queryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryStu)
{
    ui->setupUi(this);
    int ress = readfromfile();
    if(ress==-1)
    {
        QMessageBox::critical(this,"error","the file cann't open");
    }

    //stu_lines = {""};

    this->model = new QStandardItemModel;
    this->model->setHorizontalHeaderItem(0,new QStandardItem("name"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("ID"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("sex"));
        this->model->setHorizontalHeaderItem(3,new QStandardItem("age"));
        this->model->setHorizontalHeaderItem(4,new QStandardItem("dep"));
        this->model->setHorizontalHeaderItem(5,new QStandardItem("intr"));
this->ui->treeView_query->setModel(model);
}

queryStu::~queryStu()
{
    delete ui;
}

int queryStu::readfromfile()
{
    QFile file("outStu.txt");
          if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return -1;

          QTextStream in(&file);
          while (!in.atEnd()) {
              QString line = in.readLine();
              stu_lines.append(line);
              //process_line(line);
          }

      int i=0;
      for(i=0;i<stu_lines.length();i++)
      {
          qDebug()<<stu_lines.at(i);
      }
}
void queryStu::doQuery(int index, QString cnt)
{
    int i=0;
    int rw = 0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line = stu_lines.at(i);
        QStringList  sub = line.split(";");
        switch (index)
        {
        case 1:
            if(sub.at(0)==cnt)
               { rw++;
                display(rw,sub);
            }
                //qDebug()<<line;
            break;
        case 2:
            if(sub.at(1)==cnt)
            { rw++;
             display(rw,sub);
         }
                //qDebug()<<line;
            break;
        case 3:
            qDebug()<<sub.at(4);
            if(sub.at(4)==cnt)
            { rw++;
             display(rw,sub);
         }
               // qDebug()<<line;
            break;
        }

    }
    qDebug()<<"search is over";
}
void queryStu::display(int row, QStringList list)
{
    int i;
    for(i=0;i<list.length();i++)
    {
        this->model->setItem(row,i,new QStandardItem(list.at(i)));
    }
}
void queryStu::on_pushButton_search_clicked()
{
    int ind = this->ui->comboBox_search->currentIndex();
    QString cnt1 = this->ui->lineEdit_search->text();
    doQuery(ind,cnt1);
}
