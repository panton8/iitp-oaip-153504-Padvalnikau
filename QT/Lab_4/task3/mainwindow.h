#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<QInputDialog>
#include <QMessageBox>
#include <vec.h>
using namespace std;

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

private:

    Ui::MainWindow *ui;
     void Normalize(vector<int>& c);
     void AddZero(vector<int>& c, int x);
     vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k);
     int GetBit(const vector<int>& v, int b);
     vector<int> Multiply(const vector<int>& a, int x, int k);
     void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<std::pair<int, vector<int>> >& v);

};

#endif // MAINWINDOW_H
