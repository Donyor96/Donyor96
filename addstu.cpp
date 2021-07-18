#include "addstu.h"
#include "ui_addstu.h"
#include"QMessageBox"
#include"QString"
#include"QtDebug"
#include<QFile>
addStu::addStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStu)
{
    ui->setupUi(this);
}

addStu::~addStu()
{
    delete ui;
}



void addStu::on_btn_OK_clicked()
{
      QString name = this->ui->lEd_name->text();
      QString id = this->ui->lEd_id->text();
      QString sex;

      //if(this->ui->radioButton_male->isChecked())
      //{
      //    sex = "male";
      //}
      //if(this->ui->radioButton_female->isChecked())
      //{
      //    sex = "female";
      //}

      sex= this->ui->sex_buttonGroup->checkedButton()->text();

      QList<QAbstractButton *> ins_list = this->ui->ins_buttonGroup->buttons();
      QString ins;
      int i=0;
      for(i=0;i<ins_list.length();i++)
      {
          QAbstractButton *che = ins_list.at(i);//arr[i]
          if(che->isChecked())
          {
              ins+= che->text() + ",";
          }

      }

      QString age = this->ui->age_comboBox->currentText();
      QString dep = this->ui->dep_comboBox->currentText();
      if(name.length()<1||id.length()<1)
      {
          QMessageBox::critical(this,"wrong","Name or student number cannot be empty",QMessageBox::Ok);
      }
      else
      {

      QString content = name+'\n'+id+'\n'+sex+'\n'+age+'\n'+dep+'\n'+ins+'\n';//+sex;//endl
      QString cnt1 = name +";"+id+";"+sex+";"+age+";"+dep+";"+ins+ '\n';//+" "+sex
      QMessageBox msgBox;
      //msgBox.setText("student information.");
      //msgBox.setInformativeText(content);
      //msgBox.setStandardButtons(QMessageBox::Save |  QMessageBox::Cancel);   ,  ;
      //msgBox.setDefaultButton(QMessageBox::Cancel);
      //int ret = msgBox.exec();
      //msgBox.aboutQt(this,"123");
      //msgBox.about(this,"1111","any text");
      //int ret = msgBox.critical(this,"dff",content,QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
     int ret =  msgBox.information(this,"11111",content,QMessageBox::Save  | QMessageBox::Cancel);

      //qDebug()<<ret;
     switch (ret) {
        case QMessageBox::Save:
            writeinforTofile(cnt1);
            //clearUserinfo();
            clearUserinfo();
            // Save was clicked
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
            // should never be reached
            break;
      }
      }

}
void addStu::writeinforTofile(QString cnt)
{
        QFile file("outStu.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::critical(this,"wrong","the file can't be opened",QMessageBox::Ok);
            return;
         }

        QTextStream out(&file);
        out << cnt;
}
void addStu::clearUserinfo()
{
    this->ui->lEd_name->clear();
    this->ui->lEd_id->clear();
    this->ui->radioButton_male->setChecked(true);
    this->ui->age_comboBox->setCurrentIndex(0);
    this->ui->dep_comboBox->setCurrentIndex(0);


    QList<QAbstractButton *> ins_list = this->ui->ins_buttonGroup->buttons();
    QString ins;
    int i=0;
    for(i=0;i<ins_list.length();i++)
    {
        QAbstractButton *che = ins_list.at(i);//arr[i]
        che->setChecked(false);
    }

    this->ui->lEd_name->setFocus();
}
