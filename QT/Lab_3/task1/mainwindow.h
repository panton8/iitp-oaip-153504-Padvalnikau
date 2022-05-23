#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "sharedptr.h"
#include <QMainWindow>
#include "doublelist.h"
#include <memory>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void outStack();

   private slots:
       void on_pushButton_clicked();

       void on_pushButton_2_clicked();

private:
    SharedPtr<DoubleList> dl = SharedPtr<DoubleList>(new DoubleList());
    int pos;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
