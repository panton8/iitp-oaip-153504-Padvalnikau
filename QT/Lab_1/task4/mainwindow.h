#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "menu.h"
#include "orderlist.h"
#include <QFileDialog>
#include <QFile>
#include<QInputDialog>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Menu* addmenu(Menu* obj,QString dN,QString categ,double pr);
    OrderList* addOrder(OrderList *obj,int oN,int tN,QString dN,int nS,double tP);
    void inputData(QListWidgetItem *Item);
    Menu* deleteMenu(Menu* obj, int index);




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    Menu *menuList;
    OrderList *orderList;
    QListWidget *listWidget;
};
#endif // MAINWINDOW_H
