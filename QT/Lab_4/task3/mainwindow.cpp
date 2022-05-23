#include "mainwindow.h"
#include "ui_mainwindow.h"

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

Vec<int> myVector;

void MainWindow::Normalize(vector<int>& c) {
    for (size_t i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void MainWindow::AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> MainWindow::AddNum(const vector<int>& a, const vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (size_t i = 0; i < c.size(); ++i) {
        if (i < a.size()) {
            c[i] += a[i];
        }
        if (i < b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int MainWindow::GetBit(const vector<int>& v, int b) {
    return v[b] & 1;
}

vector<int> MainWindow::Multiply(const vector<int>& a, int x, int k) {

   vector<int> b = a;
    b.push_back(0);

    for (size_t i = 0; i < b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void MainWindow::GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) {

    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}

void MainWindow::on_pushButton_clicked()
{
   size_t num = QInputDialog::getText(this,"Enter the number :","Num(from 1 to 10000):",QLineEdit::Normal).toShort();

        while( num < 1 || num > 10000){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            num = QInputDialog::getText(this,"Enter the number :","Num(from 1 to 10000):",QLineEdit::Normal).toShort();
        }

        if (num == 1) {
            ui->listWidget->clear();
            ui->listWidget->addItem("1");
            return;
        }
        QString finalAnswer;
        --num;
        vector<pair<int, vector<int>>> sequence;

        for (int k = 1; num / 2 >= sequence.size(); ++k) {
           vector<int> a(k + 1);
            a[k] = 1;
            vector<vector<int>> b(k + 1);
            b[0].push_back(1);
            AddZero(b[0], k + 1);
            for (int i = 0; i < k; i++) {
                b[i + 1] = Multiply(b[i], 10, k + 1);
            }
            GenerateSequence(a, b, k, 0, sequence);
        }

        for (int i = 0; i < sequence.size(); ++i) {
            reverse(sequence[i].second.begin(), sequence[i].second.end());
        }
        sort(sequence.begin(), sequence.end());
        --num;
        vector<int> answer = sequence[num / 2].second;
        reverse(answer.begin(), answer.end());
        if (num % 2) {
            answer[0] ^= 1;
        }
        for (int k = sequence[num / 2].first; k >= 0; --k) {
            finalAnswer.push_back(QString::number(GetBit(answer, k)));
        }
        ui->listWidget->clear();
        ui->listWidget->addItem(finalAnswer);
        return ;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget_2->clear();
        int num = QInputDialog::getText(this,"Enter the number :","Num:",QLineEdit::Normal).toInt();
        while(!num){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            num = QInputDialog::getText(this,"Enter the number:","Num:",QLineEdit::Normal).toShort();
        }
        myVector.push_back(num);
                for(int i = 0; i < myVector.size(); i++)
                    ui->listWidget_2->addItem(QString::number(myVector[i]));
}


void MainWindow::on_pushButton_3_clicked()
{
    if(!myVector.empty()){
        ui->listWidget_2->clear();
        myVector.pop_back();
        for(int i = 0; i <myVector.size(); i++)
            ui->listWidget_2->addItem(QString::number(myVector[i]));
        }
        else
             QMessageBox::critical(ui->centralwidget, "Error", "Nothing to delete");
}


void MainWindow::on_pushButton_4_clicked()
{
    if(!myVector.empty()){
        ui->listWidget_2->clear();
        int num = QInputDialog::getText(this,"Enter the number :","Num:",QLineEdit::Normal).toInt();
        while(!num){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            num = QInputDialog::getText(this,"Enter the number:","Num:",QLineEdit::Normal).toShort();
        }

        int pos = QInputDialog::getText(this,"Enter the position :","Position:",QLineEdit::Normal).toInt();
        while(pos < 0 || pos > myVector.size()-1){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            pos = QInputDialog::getText(this,"Enter the position :","Position:",QLineEdit::Normal).toInt();
        }
        myVector.at(pos) = num;
        for(int i = 0; i < myVector.size(); i++)
            ui->listWidget_2->addItem(QString::number(myVector[i]));
        }
        else
            QMessageBox::critical(ui->centralwidget, "Error", "Vec is empty");
}


void MainWindow::on_pushButton_5_clicked()
{
    if(!myVector.empty()){
        myVector.clear();
        ui->listWidget_2->clear();
    }
    else
        QMessageBox::warning(ui->centralwidget, "Error", "Vector is empty yet");

}


void MainWindow::on_pushButton_6_clicked()
{
    if(!myVector.empty()){
     ui->listWidget_2->clear();

     ui->listWidget_2->addItem(QString::number(myVector.capacity()));
      }
      else
          QMessageBox::critical(ui->centralwidget, "Error", "Vec is empty");
}


void MainWindow::on_pushButton_7_clicked()
{
    int newSize = QInputDialog::getText(this,"Enter the new size :","New size:",QLineEdit::Normal).toInt();
     while(newSize < 1){
         QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
         newSize = QInputDialog::getText(this,"Enter the new size :","New size:",QLineEdit::Normal).toInt();
     }
     int oldSize = myVector.size();
     myVector.resize(newSize);
     if(oldSize < newSize){
         for(int i = oldSize ; i < myVector.size(); i++)
             myVector[i] = 0;
     }
     ui->listWidget_2->clear();
     for(int i = 0; i < myVector.size(); i++)
         ui->listWidget_2->addItem(QString::number(myVector[i]));
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->listWidget_2->clear();

       int newSize = QInputDialog::getText(this,"Enter the size of new Vec :","New size:",QLineEdit::Normal).toInt();
       while(newSize < 1){
           QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
           newSize = QInputDialog::getText(this,"Enter the size of new Vec :","New size:",QLineEdit::Normal).toInt();
       }
       int value = QInputDialog::getText(this,"Enter the value for new Vec :","Value:",QLineEdit::Normal).toInt();
           while(newSize < 1){
               QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
               newSize = QInputDialog::getText(this,"Enter the value for new Vec :","Value:",QLineEdit::Normal).toInt();
           }

           myVector.assign(newSize,value);
           for(int i = 0; i < myVector.size(); i++)
               ui->listWidget_2->addItem(QString::number(myVector[i]));
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->listWidget_2->clear();

    ui->listWidget_2->addItem(QString::number(myVector.max_size()));
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->listWidget_2->clear();
    int currentSize = myVector.size();
    ui->listWidget_2->addItem(QString::number(currentSize));
}


void MainWindow::on_pushButton_11_clicked()
{
    if(myVector.empty())
        QMessageBox::critical(ui->centralwidget, "Error", "Vector is empty");
    else{
    ui->listWidget_2->clear();
    int pos = QInputDialog::getText(this,"Enter the position to erase:","Position:",QLineEdit::Normal).toInt();
        while(pos < 0){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            pos = QInputDialog::getText(this,"Enter the position to erase:","Position:",QLineEdit::Normal).toInt();
        }
    myVector.erase(pos);
    for(int i = 0; i < myVector.size(); i++)
        ui->listWidget_2->addItem(QString::number(myVector[i]));
    }
}

