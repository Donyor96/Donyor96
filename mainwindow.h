#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"addstu.h"
#include"querystu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaddStu_triggered();

    void on_actionquery_triggered();

private:
    Ui::MainWindow *ui;
    addStu  adds;
    queryStu  queStu;
};
#endif // MAINWINDOW_H
