#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>
#include <QDialog>
#include <QTableWidget>
#include "date.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ChooseFile_clicked();

    void on_Enter_clicked();


    void on_CorrectData_clicked();

    void on_pushButton_clicked();

    void on_dateTimeEdit_dateChanged(const QDate &date);

    void on_dateTimeEdit_timeChanged(const QTime &time);

    void showTime();

    void showDate();


    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString FilePath;
    QString Bday;

    QPushButton *chooseFile;
    QDialog *wnd;
};

#endif // MAINWINDOW_H
