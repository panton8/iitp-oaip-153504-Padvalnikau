#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tempstack.h"
#include "stack.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QString expression;
double a,b,c,d,e;
QString res;

MainWindow::~MainWindow()
{
    delete ui;
}

bool pol = false;

QString MainWindow::polska()
{
   QString qwerty = expression;
   QString polska;
   TempStack *tempStack = new TempStack;
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '(' ){
            tempStack->push(expression[i]);
        }
        else if(expression[i] == ')'){
            while(tempStack->Top() != '('){
                polska += tempStack->Top();
                tempStack->pop();
                if(tempStack->Top() == '('){
                    tempStack->pop();
                    break;
                }
            }
        }
        else if(expression[i] ==  '*' || expression[i] ==  '/' || expression[i] ==  '+' || expression[i] == '-' ){
            if(priority(tempStack->Top()) < priority(expression[i]) || tempStack->isEmpty())
                 tempStack->push(expression[i]);
            else{
                polska +=  tempStack->Top();
                tempStack->pop();
                tempStack->push(expression[i]);
            }
        }
        else{
                polska += expression[i];
            }
        if( i ==  expression.length() - 1 && !tempStack->isEmpty()){
          while(!tempStack->isEmpty()){
                polska += tempStack->Top();
                tempStack->pop();
          }
            }
        }
    res = polska;
    return polska;
}

bool flag = false;

void MainWindow::on_pushButton_clicked()
{
    flag = true;
    expression =  QInputDialog::getText(this,"Enter the expression: "," Expression: ",QLineEdit::Normal);

    while(expression.isNull() || expression.toInt() || expression.isEmpty()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        expression =  QInputDialog::getText(this,"Enter the expression: "," Expression: ",QLineEdit::Normal);
    }
}

int MainWindow::priority(QChar c)
{
    char s = c.toLatin1();
    switch(s) {
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    case ')':
        return 1;
        break;
   case '(':
        return 1;
        break;
    default:
        break;
    }
}

QString MainWindow::result()
{
    Stack *stack = new Stack;
    double temp1 = 0, temp2 = 0, sum = 0;
    for(int i = 0; i < res.length(); i++){
        if(res[i] == 'a')
            stack->push(a);
        else if(res[i] == 'b')
            stack->push(b);
        else if(res[i] == 'c')
            stack->push(c);
        else if(res[i] == 'd')
            stack->push(d);
        else if(res[i] == 'e')
            stack->push(e);
        else{
            if(res[i] == '*'){
                temp1 =  stack->Top();
                stack->pop();
                temp2 = stack->Top();
                stack->pop();
                sum = temp1*temp2;
                stack->push(sum);
            }
            else if(res[i] == '/'){
                temp1=  stack->Top();
                stack->pop();
                temp2 = stack->Top();
                stack->pop();
                sum = temp2 / temp1;
                stack->push(sum);
            }

            else if(res[i] == '-'){
                temp1 =  stack->Top();
                stack->pop();
                temp2 = stack->Top();
                stack->pop();
                sum = temp2 - temp1;
                stack->push(sum);
            }

            else if(res[i] == '+'){
                temp1 =  stack->Top();
                stack->pop();
                temp2 = stack->Top();
                stack->pop();
                sum = temp1+temp2;
                stack->push(sum);
            }
        }
    }
    return (QString::number(stack->Top()));
}


void MainWindow::on_pushButton_2_clicked()
{
    pol = true;
    if(flag){
  ui->listWidget->clear();
  ui->listWidget->addItem(polska());
    }
    else
         QMessageBox::warning(ui->centralwidget, "Error", "Enter expression");
}

bool click = false;

void MainWindow::on_pushButton_3_clicked()
{
    click = true;
    a =  QInputDialog::getText(this,"enter the value of a : "," a: ",QLineEdit::Normal).toDouble();

   while(!a){
       QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        a =  QInputDialog::getText(this,"enter the value of a : "," a: ",QLineEdit::Normal).toDouble();
   }

   b =  QInputDialog::getText(this,"enter the value of b : "," b: ",QLineEdit::Normal).toDouble();

  while(!b){
      QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
     b =  QInputDialog::getText(this,"enter the value of b : "," b: ",QLineEdit::Normal).toDouble();
  }

  c =  QInputDialog::getText(this,"enter the value of c : "," c: ",QLineEdit::Normal).toDouble();

 while(!c){
     QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
    c =  QInputDialog::getText(this,"enter the value of c : "," c: ",QLineEdit::Normal).toDouble();
 }

 d =  QInputDialog::getText(this,"enter the value of d : "," d: ",QLineEdit::Normal).toDouble();

while(!d){
    QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
   d =  QInputDialog::getText(this,"enter the value of d : "," d: ",QLineEdit::Normal).toDouble();
}

   e =  QInputDialog::getText(this,"enter the value of e : "," e: ",QLineEdit::Normal).toDouble();

  while(!e){
      QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
     e =  QInputDialog::getText(this,"enter the value of e : "," e: ",QLineEdit::Normal).toDouble();
  }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(click && flag){
        if(!pol)
            polska();
    ui->listWidget->clear();
    ui->listWidget->addItem("Result of expression: " + expression + " = "  + result());
    }
    else
         QMessageBox::warning(ui->centralwidget, "Error", "Enter values and expression ");
}


void MainWindow::on_radioButton_clicked()
{
    a = 8.6; b = 2.4; c = 5.1; d = 0.3; e = 7.9;
    flag = true;
    expression = "a/(b-c)*(d+e)";
    click = true;
}


void MainWindow::on_radioButton_2_clicked()
{
      a= 7.4; b = 3.6; c = 2.8; d = 9.5; e = 0.9;
    flag = true;
    expression = "(a+b)*(c-d)/e";
    click = true;
}


void MainWindow::on_radioButton_3_clicked()
{
    a= 3.1; b = 5.4; c = 0.2; d = 9.6; e = 7.8;
    flag = true;
    expression = "a-(b+c*d)/e";
    click = true;
}


void MainWindow::on_radioButton_4_clicked()
{
    a= 1.2 ;b = 0.7; c = 9.3; d = 6.5; e = 8.4;
    flag = true;
    expression = "a/b-((c+d)*e)";
    click = true;
}


void MainWindow::on_radioButton_5_clicked()
{
    a= 9.7; b = 8.2; c = 3.6; d = 4.1; e = 0.5;
    flag = true;
    expression = "a*(b-c+d)/e";
    click = true;
}


void MainWindow::on_radioButton_6_clicked()
{
    a= 1.6; b = 4.9; c = 5.7; d = 0.8; e = 2.3;
    flag = true;
    expression = "a*(b-c)/(d+e)";
    click = true;
}


void MainWindow::on_radioButton_7_clicked()
{
    a = 0.8; b = 4.1; c = 7.9; d = 6.2; e = 3.5;
    flag = true;
    expression = "(a+b)*(c-d)/e";
    click = true;
}


void MainWindow::on_radioButton_8_clicked()
{
    a= 0.5; b = 6.1; c = 8.9; d = 2.4; e = 7.3;
    flag = true;
    expression = "a*(b-c)/(d+e)";
    click = true;
}


void MainWindow::on_radioButton_9_clicked()
{
    a= 9.1; b = 0.6; c = 2.4; d = 3.7; e = 8.5;
    flag = true;
    expression = "(a+b*c)/(d-e)";
    click = true;
}
