#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doublelist.h"

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

std::unique_ptr<DoubleList<int>> allNum = std::make_unique<DoubleList<int>>();
std::unique_ptr<DoubleList<int>> positiveNum = std::make_unique<DoubleList<int>>();
std::unique_ptr<DoubleList<int>> negativeNum = std::make_unique<DoubleList<int>>();
bool click = false;
bool sort = false;
int localSize = 0;

void MainWindow::on_pushButton_clicked(){
    int repeat = QInputDialog::getText(this,"Enter amount of numbers:","Amount:",QLineEdit::Normal).toInt();
    while(repeat < 1){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
        repeat = QInputDialog::getText(this,"Enter amount of numbers:","Amount:",QLineEdit::Normal).toInt();
    }
    for(int i = repeat;i > 0;i--){
        int Num = QInputDialog::getText(this,"Enter the number:","Number:",QLineEdit::Normal).toInt();
            while(!Num){
                QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                Num = QInputDialog::getText(this,"Enter the number:","Number:",QLineEdit::Normal).toInt();
            }
              allNum->push_Tail(Num);
    }
    click = true;
    sort = false;
}

void MainWindow::Separation()
{
       std::vector<int> num = allNum->get_nodes_forward();
       for(int i = localSize; i < num.size(); i++){
       if(num[i] > 0)
           positiveNum->push_Tail(num[i]);
       else
           negativeNum->push_Tail(num[i]);
   }
       localSize = num.size();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!click)
        QMessageBox::critical(ui->centralwidget, "Error", "The main Double Link List is empty");
    else{
        ui->listWidget->clear();
        if(!sort)
            Separation();
        std::vector<int> num = negativeNum->get_nodes_forward();
        for(int i = 0; i < num.size(); i++)
            ui->listWidget->addItem(QString::number(num[i]));
}
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!click)
         QMessageBox::critical(ui->centralwidget, "Error", "The main Double Link List is empty");
    else{
        ui->listWidget->clear();
        if(!sort)
            Separation();
        std::vector<int> num = positiveNum->get_nodes_forward();
        for(int i = 0; i < num.size(); i++)
            ui->listWidget->addItem(QString::number(num[i]));
    }
}

