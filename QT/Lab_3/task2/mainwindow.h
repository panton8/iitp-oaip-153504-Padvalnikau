#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stack.h"
#include "uniqueptr.h"
#include "QString"
#include <memory>
#include <QMainWindow>
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
    void on_popButton_clicked();

private:
    UniquePtr<Stack<int>> st = UniquePtr<Stack<int>>(new Stack<int>(10));
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
