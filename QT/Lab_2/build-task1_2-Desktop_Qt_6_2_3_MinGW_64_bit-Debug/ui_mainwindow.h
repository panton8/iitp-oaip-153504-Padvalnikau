/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *AddButton;
    QPushButton *ShowButton;
    QPushButton *toFileButton;
    QPushButton *fromFileButton;
    QPushButton *numInfoButton;
    QPushButton *CityInfoButton;
    QPushButton *deleteButton;
    QPushButton *SortButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 70, 421, 421));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(550, 70, 121, 29));
        ShowButton = new QPushButton(centralwidget);
        ShowButton->setObjectName(QString::fromUtf8("ShowButton"));
        ShowButton->setGeometry(QRect(170, 500, 121, 29));
        toFileButton = new QPushButton(centralwidget);
        toFileButton->setObjectName(QString::fromUtf8("toFileButton"));
        toFileButton->setGeometry(QRect(540, 270, 151, 29));
        fromFileButton = new QPushButton(centralwidget);
        fromFileButton->setObjectName(QString::fromUtf8("fromFileButton"));
        fromFileButton->setGeometry(QRect(520, 310, 191, 29));
        numInfoButton = new QPushButton(centralwidget);
        numInfoButton->setObjectName(QString::fromUtf8("numInfoButton"));
        numInfoButton->setGeometry(QRect(560, 190, 93, 29));
        CityInfoButton = new QPushButton(centralwidget);
        CityInfoButton->setObjectName(QString::fromUtf8("CityInfoButton"));
        CityInfoButton->setGeometry(QRect(560, 230, 93, 29));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(550, 110, 121, 29));
        SortButton = new QPushButton(centralwidget);
        SortButton->setObjectName(QString::fromUtf8("SortButton"));
        SortButton->setGeometry(QRect(550, 150, 121, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "Add call info", nullptr));
        ShowButton->setText(QCoreApplication::translate("MainWindow", "Show all info", nullptr));
        toFileButton->setText(QCoreApplication::translate("MainWindow", "Save call info in File", nullptr));
        fromFileButton->setText(QCoreApplication::translate("MainWindow", "Take call info from File", nullptr));
        numInfoButton->setText(QCoreApplication::translate("MainWindow", "PhoneInfo", nullptr));
        CityInfoButton->setText(QCoreApplication::translate("MainWindow", "CityInfo", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete call data", nullptr));
        SortButton->setText(QCoreApplication::translate("MainWindow", "SortByTalkTime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
