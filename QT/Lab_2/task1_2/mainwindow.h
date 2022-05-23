#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ATS.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFileDialog>
#include <QFile>
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
    int getAvailableIndex();
    void addInTail(ATS** ats, ATS* new_ats);
    void numInfo(QString phone);
    void searchShow(ATS* new_ats);
    void cityInfo(QString city);
    void Show();
    void fromFile();
    void toFile();
    void qSort(ATS** ats, int last);

private slots:
    void on_AddButton_clicked();
    void on_ShowButton_clicked();
    void on_toFileButton_clicked();
    void on_fromFileButton_clicked();
    void on_numInfoButton_clicked();
    void on_CityInfoButton_clicked();
    void on_deleteButton_clicked();
    void on_SortButton_clicked();

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    int  Head, Tail;
    ATS** atsList;
    bool* available;
};
#endif // MAINWINDOW_H
