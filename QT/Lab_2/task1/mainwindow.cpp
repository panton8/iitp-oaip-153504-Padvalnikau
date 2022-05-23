#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) ,Head(NULL), Tail(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    while (Head)                       //Пока по адресу на начало списка что-то есть
        {
            Tail = Head->next;             //Резервная копия адреса следующего звена списка
            delete Head;                   //Очистка памяти от первого звена
            Head = Tail;                   //Смена адреса начала на адрес следующего элемента
        }
}

int num = 1;

void MainWindow::AddInEnd(short regNum, QString author, QString title, short yearPublishing, QString publishingHouse, short pageNum)
 {
  Book *temp = new Book;               //Выделение памяти под новый элемент структуры
  temp->next = NULL;                   //Указываем, что изначально по следующему адресу пусто
  temp->regNum = regNum;                         //Записываем значение в структуру
  temp->author = author;
  temp->title = title;
  temp->yearPublishing = yearPublishing;
  temp->publishingHouse = publishingHouse;
  temp->pageNum = pageNum;
   if (Head != NULL)                    //Если список не пуст
   {
       temp->prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
       Tail->next = temp;               //Указываем адрес следующего за хвостом элемента
       Tail = temp;                     //Меняем адрес хвоста
       num++;
   }
   else //Если список пустой
   {
       temp->prev = NULL;               //Предыдущий элемент указывает в пустоту
       Head = Tail = temp;
       num++;                   //Голова=Хвост=тот элемент, что сейчас добавили
   }
}

void MainWindow::AddInStart(short regNum, QString author, QString title, short yearPublishing, QString publishingHouse, short pageNum)
{
   Book *temp = new Book;               //Выделение памяти под новый элемент структуры
   temp->prev = NULL;                   //Указываем, что изначально по следующему адресу пусто
   temp->regNum = regNum;                         //Записываем значение в структуру
   temp->author = author;
   temp->title = title;
   temp->yearPublishing = yearPublishing;
   temp->publishingHouse = publishingHouse;
   temp->pageNum = pageNum;
   temp->next = Head;
    if (Head != NULL)
       Head->prev = temp;
    if(num == 0)
        Head = Tail = temp;
    else
        Head = temp;
    num++;
}

void MainWindow::Show(){
    Book *temp = Head;
    QTableWidget *table = new QTableWidget();
    table->setRowCount(num);
    table->setColumnCount(6);

     table->resize(700,700);

    QTableWidgetItem *itm1 = new QTableWidgetItem("Reg number");
    table->setItem(0, 0, itm1);


    QTableWidgetItem *itm2 = new QTableWidgetItem("Author");
    table->setItem(0, 1, itm2);


    QTableWidgetItem *itm3 = new QTableWidgetItem("Title");
    table->setItem(0, 2, itm3);


    QTableWidgetItem *itm4 = new QTableWidgetItem("Publication year");
    table->setItem(0, 3, itm4);


    QTableWidgetItem *itm5 = new QTableWidgetItem("Publishing house");
    table->setItem(0, 4, itm5);


    QTableWidgetItem *itm6 = new QTableWidgetItem("Number of page");
    table->setItem(0, 5, itm6);

    int pos = 1;

    while (temp != NULL){      //Пока не встретим пустое значение
        QTableWidgetItem *itm0 = new QTableWidgetItem(QString::number(temp->regNum));
        QTableWidgetItem *itm1 = new QTableWidgetItem(temp->author);
        QTableWidgetItem *itm2 = new QTableWidgetItem(temp->title);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(temp->yearPublishing));
        QTableWidgetItem *itm4 = new QTableWidgetItem(temp->publishingHouse);
        QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(temp->pageNum));


        table->setItem(pos, 0, itm0);
        table->setItem(pos, 1, itm1);
        table->setItem(pos, 2, itm2);
        table->setItem(pos, 3, itm3);
        table->setItem(pos, 4, itm4);
        table->setItem(pos, 5, itm5);
        temp = temp->next;
        pos++;
         }
    table->show();
}

void MainWindow::on_pushButton_clicked()
{
    Show();
}

void MainWindow::showForSearch(Book* book){
    QTableWidget *table = new QTableWidget();
     table->setRowCount(2);
     table->setColumnCount(6);
     table->resize(800,600);

    QTableWidgetItem *itm1 = new QTableWidgetItem("Reg number");
    table->setItem(0, 0, itm1);


    QTableWidgetItem *itm2 = new QTableWidgetItem("Author");
    table->setItem(0, 1, itm2);


    QTableWidgetItem *itm3 = new QTableWidgetItem("Title");
    table->setItem(0, 2, itm3);


    QTableWidgetItem *itm4 = new QTableWidgetItem("Publication year");
    table->setItem(0, 3, itm4);


    QTableWidgetItem *itm5 = new QTableWidgetItem("Publishing house");
    table->setItem(0, 4, itm5);


    QTableWidgetItem *itm6 = new QTableWidgetItem("Number of page");
    table->setItem(0, 5, itm6);

    QTableWidgetItem *search0 = new QTableWidgetItem(QString::number(book->regNum));
    QTableWidgetItem *search1 = new QTableWidgetItem(book->author);
    QTableWidgetItem *search2 = new QTableWidgetItem(book->title);
    QTableWidgetItem *search3 = new QTableWidgetItem(QString::number(book->yearPublishing));
    QTableWidgetItem *search4 = new QTableWidgetItem(book->publishingHouse);
    QTableWidgetItem *search5 = new QTableWidgetItem(QString::number(book->pageNum));


    table->setItem(1, 0,search0);
    table->setItem(1, 1, search1);
    table->setItem(1, 2, search2);
    table->setItem(1, 3, search3);
    table->setItem(1, 4, search4);
    table->setItem(1, 5, search5);

    for(int i = 0; i < 6; i++)
        table->item(1, i)->setBackground(Qt::darkGray);
    table->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    short regNum = QInputDialog::getText(this,"Enter number of registration:","RegNum:",QLineEdit::Normal).toShort();

    while(!regNum){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        regNum = QInputDialog::getText(this,"Enter number of registration:","RegNum:",QLineEdit::Normal).toShort();
    }

    QString author =  QInputDialog::getText(this,"Enter author's name: "," Author's name: ",QLineEdit::Normal);

    while(author.isNull() || author.toInt() || author.isEmpty()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");

        author =  QInputDialog::getText(this,"Enter author's name: "," Author's name: ",QLineEdit::Normal);
    }

    QString title =  QInputDialog::getText(this,"Enter book's name: ","  Title:",QLineEdit::Normal);

    while(title.isNull() || title.isEmpty()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        title =  QInputDialog::getText(this,"Enter book's name: ","  Title:",QLineEdit::Normal);
    }


    short yearPublishing = QInputDialog::getText(this,"Enter yearPublishing:","YearPublishing:",QLineEdit::Normal).toShort();

    while(!yearPublishing || (yearPublishing > 2022 || yearPublishing < 1))
    {
           QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
           yearPublishing = QInputDialog::getText(this,"Enter yearPublishing:","YearPublishing:",QLineEdit::Normal).toShort();
}

    QString publishingHouse =  QInputDialog::getText(this,"Enter name of publishingHouse: ","PublishingHouse:",QLineEdit::Normal);

    while(publishingHouse.isNull() || publishingHouse.toInt() || publishingHouse.isEmpty()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        publishingHouse =  QInputDialog::getText(this,"Enter name of publishingHouse: ","PublishingHouse:",QLineEdit::Normal);
    }

    short pageNum = QInputDialog::getText(this,"Enter number of pages:","PageNum:",QLineEdit::Normal).toShort();

    while(!pageNum){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        pageNum = QInputDialog::getText(this,"Enter number of pages:","PageNum:",QLineEdit::Normal).toShort();
    }

    AddInEnd(regNum,author, title, yearPublishing, publishingHouse, pageNum);
}

void MainWindow::regnumSearch(){
    short regNum =  QInputDialog::getText(this,"Enter number of registration for searching:","RegNum:",QLineEdit::Normal).toShort();

    while(!regNum){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        regNum = QInputDialog::getText(this,"Enter number of registration for searching:","RegNum:",QLineEdit::Normal).toShort();
    }
    bool checkSearch = false;
    if(Head == nullptr)
        QMessageBox::critical(ui->centralwidget, "", "The list is empty");
       Book* temp = Head;
       while(temp != nullptr)
       {
           if(temp->regNum == regNum){
               showForSearch(temp);
               checkSearch = true;
           }
           temp = temp->next;
       }
       if(!checkSearch && Head != nullptr)
           QMessageBox::critical(ui->centralwidget, "", "Books with this number not found");

}
void MainWindow::swap( Book* a, Book* b )
{
    Book temp = *a;
    a->regNum = b->regNum;
    a->author = b->author;
    a->title = b->title;
    a->yearPublishing = b->yearPublishing;
    a->publishingHouse = b->publishingHouse;
    a->pageNum = b->pageNum;
    b->regNum = temp.regNum;
     b->author = temp.author;
     b->title = temp.title;
     b->yearPublishing = temp.yearPublishing;
      b->publishingHouse = temp.publishingHouse;
      b->pageNum = temp.pageNum;
}

Book* MainWindow::partition(Book *left, Book *right)
{
    short pivot = right->yearPublishing;
    // similar to i = l-1 for array implementation
    Book *i = left->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Book *j = left; j != right; j = j->next)
    {
        if (j->yearPublishing <= pivot)
        {
            // Similar to i++ for array
            i = (i == NULL)? left : i->next;

            swap(i,j);
        }
    }
    i = (i == NULL)? left : i->next; // Similar to i++

    swap(i, right);
    return i;
}

void MainWindow::sorting(Book* left, Book *h)
{
    if (h != NULL && left != h && left != h->next)
    {
        Book *p = partition(left, h);
        sorting(left, p->prev);
        sorting(p->next, h);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    regnumSearch();
}


void MainWindow::authorSearch(){
    QString author =  QInputDialog::getText(this,"Enter author's name for searching:","Author:",QLineEdit::Normal);

    bool checkSearch = false;
    if(Head == nullptr)
        QMessageBox::critical(ui->centralwidget, "", "The list is empty");
       Book* temp = Head;
       while(temp != nullptr)
       {
           if(temp->author == author){
           showForSearch(temp);
           checkSearch = true;
           }
           temp = temp->next;
       }
       if(!checkSearch && Head != nullptr)
           QMessageBox::critical(ui->centralwidget, "", "Books by this author not found");

}

void MainWindow::on_pushButton_5_clicked()
{
    authorSearch();
}

void MainWindow::TitleYearSearch(){
    QString title =  QInputDialog::getText(this,"Enter the book's name for searching:"," Title:",QLineEdit::Normal);
    short yearPublishing = QInputDialog::getText(this,"Enter the year of publishing for searching:","Year:",QLineEdit::Normal).toShort();
    bool checkSearch = false;
    if(Head == nullptr)
        QMessageBox::critical(ui->centralwidget, "", "The list is empty");
       Book* temp = Head;
       while(temp != nullptr)
       {
           if(temp->title == title && temp->yearPublishing == yearPublishing){
               showForSearch(temp);
               checkSearch = true;
       }
             temp = temp->next;
       }
       if(!checkSearch)
           QMessageBox::critical(ui->centralwidget, "", "Books with such title and year of publishing not found");
}

void MainWindow::on_pushButton_6_clicked()
{
    TitleYearSearch();
}

void MainWindow::on_pushButton_4_clicked()
{
   sorting(Head,Tail);
}

void MainWindow::deleteBook(Book** Head, Book* delItem)
{
    if (*Head == NULL || delItem == NULL)
        return;

    /* If node to be deleted is head node */
    if (*Head == delItem)
        *Head = delItem->next;

    /* Change next only if node to be
    deleted is NOT the last node */
    if (delItem->next != NULL)
        delItem->next->prev = delItem->prev;

    /* Change prev only if node to be
    deleted is NOT the first node */
    if (delItem->prev != NULL)
        delItem->prev->next = delItem->next;

    /* Finally, free the memory occupied by del*/
    free(delItem);
    return;
}

void MainWindow::on_pushButton_7_clicked()
{
    QString title =  QInputDialog::getText(this,"Enter the book's name for searching:"," Title:",QLineEdit::Normal);
    QString author =  QInputDialog::getText(this,"Enter author's name for searching:","Author:",QLineEdit::Normal);
    bool del = false;
    Book* temp = Head;
    while(temp != nullptr){
        if(temp->author == author && temp->title == title){
            deleteBook(&Head,temp);
            del = true;
            num--;
        }
        temp = temp->next;
}
    if(!del)
        QMessageBox::critical(ui->centralwidget, "", "This author's book was not found");
}

void MainWindow::DataFromFile(){
    bool correct = true;
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::ReadOnly))
        qWarning("Can't open file for reading");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
        for(int i = 0; !in.atEnd(); i++)
{
            Book *temp = new Book;               //Выделение памяти под новый элемент структуры
            temp->next = NULL;                   //Указываем, что изначально по следующему адресу пусто

            QString regNum = file.readLine();
            if((regNum.isNull() || regNum.isEmpty() || !regNum.toUShort()) && correct){
                QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
                correct = false;
                break;
            }
            else if(correct && !regNum.isEmpty() && regNum.toUShort()){
                temp->regNum = regNum.toShort();}   //Записываем значение в структуру

            QString author = file.readLine();
            if((author.isNull() || author.isEmpty()) && correct){
                QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
                        correct = false;
                        break;
        }
            else if(!author.isEmpty() && correct)
                temp->author = author.replace(author.length() - 2,2,"");

           QString title = file.readLine();
           if((title.isEmpty() || title.isNull()) && correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!title.isEmpty() && correct)
               temp->title = title.replace(title.length() - 2, 2 , "");

           QString yearPublishing = file.readLine();
           if((yearPublishing.isEmpty() || !yearPublishing.toShort() || yearPublishing.isNull()) && correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!yearPublishing.isEmpty() && yearPublishing.toUShort() && correct)
               temp->yearPublishing = yearPublishing.toShort();

           QString publishingHouse = file.readLine();    
           if((publishingHouse.isEmpty() || publishingHouse.isNull())&& correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if((!publishingHouse.isEmpty()) && correct)
               temp->publishingHouse = publishingHouse.replace(publishingHouse.length()-2, 2, "");

           QString pageNum = file.readLine();
           if((pageNum.isNull() || pageNum.isEmpty() || !pageNum.toUShort() )&& correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!pageNum.isEmpty() && pageNum.toUShort() && correct)
               temp->pageNum = pageNum.toShort();
           if(correct){
            if ( Head != NULL)                    //Если список не пуст
            {
                temp->prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
                Tail->next = temp;               //Указываем адрес следующего за хвостом элемента
                Tail = temp;                     //Меняем адрес хвоста
                num++;
            }
            else //Если список пустой
            {
                temp->prev = NULL;               //Предыдущий элемент указывает в пустоту
                Head = Tail = temp;
                num++;                   //Голова=Хвост=тот элемент, что сейчас добавили
            }
                }
        }
    file.close();
}

void MainWindow::DataToFile(){
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));;
    if(!file.open(QIODevice::WriteOnly))
        qWarning("Can't open file for reading");
    QTextStream out(&file);
    Book* temp = Head;
    int table = 1;
    while(temp != nullptr)
    {out << "#" << table << '\n' << "Registration number: " << temp->regNum << '\n' << "Auhor: " << temp->author<< '\n' << "Books name: " << temp->title<< '\n' << "Year of publishing: "<< temp->yearPublishing<< '\n' <<"Publishing house: "<< temp->publishingHouse<< '\n'<< "Number of pages: "<< temp->pageNum<<'\n';
        temp = temp->next;
                table++;
    }

    file.close();
}
void MainWindow::on_pushButton_8_clicked()
{
    DataFromFile();
}


void MainWindow::on_pushButton_9_clicked()
{
    DataToFile();
}


void MainWindow::on_pushButton_10_clicked()
{
    short regNum = QInputDialog::getText(this,"Enter number of registration:","RegNum:",QLineEdit::Normal).toShort();

    while(!regNum || regNum < 1000 || regNum > 9999){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                "regNum format: xxxx");
        regNum = QInputDialog::getText(this,"Enter number of registration:","RegNum:",QLineEdit::Normal).toShort();
    }

    QString author =  QInputDialog::getText(this,"Enter author's name: "," Author's name: ",QLineEdit::Normal);

    while(author.toInt() || author.isEmpty() || author.isNull()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        author =  QInputDialog::getText(this,"Enter author's name: "," Author's name: ",QLineEdit::Normal);
    }

    QString title =  QInputDialog::getText(this,"Enter book's name: ","  Title:",QLineEdit::Normal);

    while(title.isEmpty() || title.isNull()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        title =  QInputDialog::getText(this,"Enter book's name: ","  Title:",QLineEdit::Normal);
    }


    short yearPublishing = QInputDialog::getText(this,"Enter yearPublishing:","YearPublishing:",QLineEdit::Normal).toShort();

    while(!yearPublishing || (yearPublishing > 2022 || yearPublishing < 1))
    {
           QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
           yearPublishing = QInputDialog::getText(this,"Enter yearPublishing:","YearPublishing:",QLineEdit::Normal).toShort();
}

    QString publishingHouse =  QInputDialog::getText(this,"Enter name of publishingHouse: ","PublishingHouse:",QLineEdit::Normal);

    while(publishingHouse.toInt() || publishingHouse.isEmpty() || publishingHouse.isNull()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        publishingHouse =  QInputDialog::getText(this,"Enter name of publishingHouse: ","PublishingHouse:",QLineEdit::Normal);
    }

    short pageNum = QInputDialog::getText(this,"Enter number of pages:","PageNum:",QLineEdit::Normal).toShort();

    while(!pageNum){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        pageNum = QInputDialog::getText(this,"Enter number of pages:","PageNum:",QLineEdit::Normal).toShort();
    }

    AddInStart(regNum,author, title, yearPublishing, publishingHouse, pageNum);
}

