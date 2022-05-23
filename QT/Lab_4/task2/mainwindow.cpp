#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

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


void MainWindow::on_file_clicked()
{
    path = QFileDialog::getOpenFileName(this, "", "D:/bsuir/OAiP/", "CPP files (*.cpp);");

    if (path.isEmpty())
        return;

    QFont font;
    font.setPixelSize(20);

    QDialog *wnd = new QDialog(this);

    wnd->resize(1400, 1000);

    QTextEdit *code = new QTextEdit(wnd);

    code->resize(600, 1000);

    code->setFont(font);

    QFile f(path);

    f.open(QFile::ReadOnly);

    QString buf = f.readAll();

    path = "";

    f.close();

    wnd->setModal(true);

    code->setText(buf);

    QTextEdit *parsing_ = new QTextEdit(wnd);

    parsing_->resize(800, 1000);

    parsing_->setFont(font);

    parsing_->move(600, 0);

    std::string input = buf.toStdString();

    parser prs(input.c_str());

    prs.parse();

    parsing_->setFont(font);

    parsing_->setText(prs.get_info());

    wnd->show();

}


void MainWindow::on_input_clicked()
{
    QFont font;
    font.setPixelSize(20);

    inp_wnd = new QDialog(this);

    inp_wnd->resize(1400, 600);

    inp_code = new QTextEdit(inp_wnd);

    QPushButton *parse_btn = new QPushButton("Click", inp_wnd);

    parse_btn->setFont(font);

    parse_btn->move(630, 500);

    inp_code->resize(600, 400);

    inp_code->setFont(font);

    path = "";

    inp_wnd->setModal(true);

    parsing = new QTextEdit(inp_wnd);

    parsing->resize(800, 400);

    parsing->setFont(font);

    parsing->move(600, 0);

    parsing->setDisabled(true);

    connect(parse_btn, SIGNAL(clicked()), this, SLOT(start_parsing()));

    parsing->setFont(font);

    inp_wnd->show();
}

void MainWindow::start_parsing()
{

    QString code = inp_code->toPlainText();

    if (code.isEmpty())
        return;

    parsing->clear();

    parsing->setEnabled(true);

    std::string _code = code.toStdString();

    parser prs(_code.c_str());

    prs.parse();

    parsing->setText(prs.get_info());

}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();

    std::string s1 =  QInputDialog::getText(this,"Enter the word:","Word#1",QLineEdit::Normal).toStdString();

    char str1[s1.size() + 1];
   for(int i =0; i < s1.size() + 1;i++)
       str1[i] = s1[i];

   std::string s2 =   QInputDialog::getText(this,"Enter the word:","Word#2",QLineEdit::Normal).toStdString();

   char str2[s2.size() + 1];
   for(int i =0; i < s2.size() + 1;i++)
       str2[i] = s2[i];


    int symbols = QInputDialog::getText(this,"Enter the number of characters to add:","Num of characters:",QLineEdit::Normal).toInt();
    while(symbols < 1 || symbols > s2.size()){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
        symbols = QInputDialog::getText(this,"Enter the number of characters to add:","Num of characters:",QLineEdit::Normal).toInt();
    }
    MyString res;
    ui->listWidget->addItem( res.Mystrncat(str1,str2, symbols));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();

    std::string s1 =  QInputDialog::getText(this,"Enter the word:","Word",QLineEdit::Normal).toStdString();

    char str1[s1.size() + 1];
   for(int i =0; i < s1.size() + 1;i++)
       str1[i] = s1[i];

   MyString res;
   ui->listWidget->addItem(QString::number(res.Mystrlen(str1)));

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();

    std::string s1 =  QInputDialog::getText(this,"Enter the word:","Word#1",QLineEdit::Normal).toStdString();

    char str1[s1.size() + 1];
   for(int i =0; i < s1.size() + 1;i++)
       str1[i] = s1[i];

   std::string s2 = QInputDialog::getText(this,"Enter the word:","Word#2",QLineEdit::Normal).toStdString();

   char str2[s2.size() + 1];
   for(int i =0; i < s2.size() + 1;i++)
       str2[i] = s2[i];

   int symbols = QInputDialog::getText(this,"Enter the number of characters for comparison:","Num of characters:",QLineEdit::Normal).toInt();
   while(symbols < 1 || symbols > s1.size()){
       QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
       symbols = QInputDialog::getText(this,"Enter the number of characters for comparison:","Num of characters:",QLineEdit::Normal).toInt();
   }

   MyString res;
   int result = res.Mymemcmp(str1,str2,symbols);

   ui->listWidget->addItem(QString::number(result));
   ui->listWidget->addItem("Conclusion:");


   if(result > 0){
       ui->listWidget->addItem(str1);
       ui->listWidget->addItem("is greater than ");
       ui->listWidget->addItem(str2);
   }
   else if (result < 0){
   ui->listWidget->addItem(str1);
   ui->listWidget->addItem("is less than ");
   ui->listWidget->addItem(str2);
   }
   else {
       ui->listWidget->addItem(str1);
       ui->listWidget->addItem("is the same as  ");
       ui->listWidget->addItem(str2);
   }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();

    std::string s1 =  QInputDialog::getText(this,"Enter the word:","Word#1",QLineEdit::Normal).toStdString();

    char str1[s1.size() + 1];
   for(int i =0; i < s1.size() + 1;i++)
       str1[i] = s1[i];

   std::string s2 = QInputDialog::getText(this,"Enter the word:","Word#2",QLineEdit::Normal).toStdString();

   char str2[s2.size() + 1];
   for(int i =0; i < s2.size() + 1;i++)
       str2[i] = s2[i];

   int symbols = QInputDialog::getText(this,"Enter the number of characters for comparison:","Num of characters:",QLineEdit::Normal).toInt();
   while(symbols < 1 || symbols > s1.size()){
       QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
       symbols = QInputDialog::getText(this,"Enter the number of characters for comparison:","Num of characters:",QLineEdit::Normal).toInt();
   }

   MyString res;
   int result = res.Mystrncmp(str1,str2,symbols);

   ui->listWidget->addItem(QString::number(result));
   ui->listWidget->addItem("Conclusion:");


   if(result == 0){
       ui->listWidget->addItem(str1);
       ui->listWidget->addItem("is equal to");
       ui->listWidget->addItem(str2);
   }
   else if (result > 0){
   ui->listWidget->addItem(str1);
   ui->listWidget->addItem("is greater than ");
   ui->listWidget->addItem(str2);
   }
   else {
       ui->listWidget->addItem(str2);
       ui->listWidget->addItem("is greater than");
       ui->listWidget->addItem(str1);
   }

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->listWidget->clear();

    std::string s1 =  QInputDialog::getText(this,"Enter the word:","Word#1",QLineEdit::Normal).toStdString();

    char str1[s1.size() + 1];
   for(int i =0; i < s1.size() + 1;i++)
       str1[i] = s1[i];

   std::string s2 = QInputDialog::getText(this,"Enter the word:","Word#2",QLineEdit::Normal).toStdString();

   char str2[s2.size() + 1];
   for(int i =0; i < s2.size() + 1;i++)
       str2[i] = s2[i];

   ui->listWidget->addItem("Before:");
   ui->listWidget->addItem(str1);
   ui->listWidget->addItem(str2);

   MyString res;
   std::string temp = res.Mystrcpy(str1,str2);

   char str11[s2.size() + 1];
   for(int i =0; i  < s2.size() + 1; i++)
       str11[i] = temp[i];
   ui->listWidget->addItem("\nAfter:");
   ui->listWidget->addItem(str11);
   ui->listWidget->addItem(str2);
}
