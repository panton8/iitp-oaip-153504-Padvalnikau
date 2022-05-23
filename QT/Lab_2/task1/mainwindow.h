#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <book.h>
#include<QInputDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) ;
    ~MainWindow();
    void Show();
    void AddInEnd(short regNum, QString author, QString title, short yearPublishing, QString publishingHouse, short pageNum);
    void AddInStart(short regNum, QString author, QString title, short yearPublishing, QString publishingHouse, short pageNum);
    void regnumSearch();
    void authorSearch();
    void sorting(Book *left, Book *right);
    void TitleYearSearch();
    Book* partition(Book *l, Book *h);
    void swap(Book* a, Book* b);
    void showForSearch(Book* book);
    void deleteBook(Book** Head, Book* delItem);
    void DataFromFile();
    void DataToFile();
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

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    Book *Head, *Tail, book;
};
#endif // MAINWINDOW_H
