#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new HashTable<int>();
    mS = new MaxStack();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int num = QInputDialog::getText(this,"Enter the value:","Value :",QLineEdit::Normal).toInt();

     while(!num){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         num = QInputDialog::getText(this,"Enter the value:","Value :",QLineEdit::Normal).toInt();
     }

     int key = QInputDialog::getText(this,"Enter the key:","Key :",QLineEdit::Normal).toInt();

      while(!key){
          QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
          key = QInputDialog::getText(this,"Enter the key:","Key :",QLineEdit::Normal).toInt();
      }


     table->Add(key,num);


     ui->listWidget->clear();

     for(int i = 0; i < table->capacity;i++)
         {
             Stack<int> * tmp = table->Find(i);
             if(tmp != nullptr)
             {
                 ui->listWidget->addItem("Num of Hash:" + QString::number(i));
                 for(int j = tmp->index - 1;j >= 0;j--)
                     ui->listWidget->addItem(QString::number(tmp->arr[j]));
             }
         }
}

void MainWindow::on_pushButton_2_clicked()
{

    int  *found = new int[table->capacity];
        for(int i = 0; i < table->capacity;i++){
            Stack<int> * tmp = table->Find(i);
            if(tmp != nullptr)
            {
                found[i] = tmp->arr[0];
                for(int j = tmp->index-1;j >= 0;j--){
                    if(found[i] < tmp->arr[j])
                        found[i] = tmp->arr[j];
                }
            }
            else
                found[i] = 0;
        }

        int max = found[0];
        int numofstack = 0;
        for(int i = 0; i < table->capacity; i++) {
            if (found[i] > max){
                numofstack = i;
                max = found[i];
            }

        }

     ui->listWidget->clear();

     ui->listWidget->addItem("Num of stack with MaxValue: " + QString::number(numofstack));

     for(int i = 0; i < table->capacity;i++)
         {
             Stack<int> * tmp = table->Find(i);
             if(tmp != nullptr && i == numofstack)
             {
                 ui->listWidget->addItem("Num of Hash:" + QString::number(i));
                 for(int j = tmp->index - 1;j >= 0;j--)
                     ui->listWidget->addItem(QString::number(tmp->arr[j]));
             }
         }
}

