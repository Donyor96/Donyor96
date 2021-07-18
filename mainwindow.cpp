#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addstu.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionaddStu_triggered()
{

   adds.show();
}

void MainWindow::on_actionquery_triggered()
{
queStu.show();
}
