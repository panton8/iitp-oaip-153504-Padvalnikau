#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>


QString symbols;
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

bool click = false;

void MainWindow::useFile(){
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::ReadOnly))
        qWarning("Can't open file for reading");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
          symbols = in.readAll();
          ui->textEdit->append(symbols);
}
    file.close();
    click = true;
}
void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    useFile();
    click = true;
}

void MainWindow::checkSymbols(){

    int index1 = 0;
    bool check = true;
    Stack *stack = new Stack;
    symbols = ui->textEdit->toPlainText();
    QString copy = symbols;
    for(int i = 0; i < copy.length(); i++){
        if(copy[i] == '(' || copy[i] == ')' || copy[i] == '[' || copy[i] == ']' || copy[i] == '{' || copy[i] == '}'){
            continue;
        }
        else
             copy.replace(i,1,' ');
    }
    for(int i = 0; i < copy.length(); i++){
        if(copy[i] == '(' || copy[i] == '[' || copy[i] == '{'){
            stack->push(copy[i]);
            index1++;
        }
        else if(copy[i] == ')'){
            index1++;
            if(stack->Top() == '(')
                stack->pop();
            else{
                check = false;
                break;
        } }
        else if(copy[i] == ']'){
            index1++;
            if(stack->Top() == '[')
                stack->pop();
            else{
                check = false;
                break;
            }
            }
        else if(copy[i] == '}'){
            index1++;
            if(stack->Top() == '{')
                stack->pop();
            else{
                check = false;
                break;
            }
        }
 }
    bool repeat = true;
    QString ind;
    int index2 = 0;
   if(stack->isEmpty() && check){
        ui->textEdit->clear();
        for(int i = 0; i < symbols.length(); i++)
                ui->textEdit->insertPlainText(symbols[i]);
         QMessageBox::information(this, "Result of checking:", "Success");
    }  
    else{
        ui->textEdit->clear();
         for(int i = 0; i < symbols.length(); i++){
             if(symbols[i] == '(' || symbols[i] == ')' || symbols[i] == '[' || symbols[i] == ']' || symbols[i] == '{' || symbols[i] == '}')
                 index2++;
             if(index1 != index2 || !repeat)
                 ui->textEdit->insertPlainText(symbols[i]);
             else{
                 if(repeat){
                 ind.setNum(i+1);
                 ui->textEdit->setTextColor( QColor( "red" ) );
                 ui->textEdit->insertPlainText(symbols[i]);
                 ui->textEdit->setTextColor( QColor( "black" ));
                 repeat = false;
                 }
             }
         }
          QMessageBox::warning(this, "Result of checking:", "Fail on index: " + ind);
   }
}

void MainWindow::fastCheck()
{
    int index1 = 0;
    bool check = true;
    Stack *stack = new Stack;
    symbols = ui->textEdit->toPlainText();
    QString copy = symbols;
    for(int i = 0; i < copy.length(); i++){
        if(copy[i] == '(' || copy[i] == ')' || copy[i] == '[' || copy[i] == ']' || copy[i] == '{' || copy[i] == '}'){
            continue;
        }
        else
             copy.replace(i,1,' ');
    }
    for(int i = 0; i < copy.length(); i++){
        if(copy[i] == '(' || copy[i] == '[' || copy[i] == '{'){
            stack->push(copy[i]);
            index1++;
        }
        else if(copy[i] == ')'){
            index1++;
            if(stack->Top() == '(')
                stack->pop();
            else{
                check = false;
                break;
        } }
        else if(copy[i] == ']'){
            index1++;
            if(stack->Top() == '[')
                stack->pop();
            else{
                check = false;
                break;
            }
            }
        else if(copy[i] == '}'){
            index1++;
            if(stack->Top() == '{')
                stack->pop();
            else{
                check = false;
                break;
            }
        }
 }
    QString ind;
    ind.setNum(index1);
    int index2 = 0;
     if(stack->isEmpty() && check){
         ui->textEdit->clear();
     for(int i = 0; i < copy.length(); i++){
             ui->textEdit->insertPlainText(copy[i]);
 }
      QMessageBox::information(this, "Result of checking:", "Success");}
     else{
         ui->textEdit->clear();
          for(int i = 0; i < copy.length(); i++){
              if(symbols[i] == '(' || symbols[i] == ')' ||  symbols[i] == '[' || symbols[i] == ']' || symbols[i] == '{' || symbols[i] == '}'){
                  index2++;
                  if(index1 != index2)
                    ui->textEdit->insertPlainText(copy[i]);
                  else{
                      ui->textEdit->setTextColor( QColor( "red" ) );
                      ui->textEdit->insertPlainText(copy[i]);
                      ui->textEdit->setTextColor( QColor( "black" ));
                  }
              }

            }
           QMessageBox::warning(this, "Result of checking:", "Fail on index: " + ind);

}
}
void MainWindow::on_pushButton_4_clicked()
{
        checkSymbols();
}

void MainWindow::on_pushButton_2_clicked()
{
    fastCheck();
}

