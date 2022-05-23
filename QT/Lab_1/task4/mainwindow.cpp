#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QMessageBox>

int menuSize = 1;
int orderSize = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    orderList = new  OrderList[orderSize];
    menuList = new Menu[menuSize];
}

MainWindow::~MainWindow()
{
    delete ui;
}

Menu* MainWindow::addmenu(Menu* obj,QString dN,QString categ,double pr){
    if(menuSize == 1)
        obj[0].setData(dN,categ,pr);
    else{
        Menu* temp_obj = new Menu[menuSize];
        for(int i = 0; i < menuSize - 1; i++)
            temp_obj[i] = obj[i];
        delete[] obj;
        obj = temp_obj;
        obj[menuSize - 1].setData(dN,categ,pr);
    }
    menuSize++;
    return obj;
}

OrderList* MainWindow::addOrder(OrderList *obj, int oN,int tN,QString dN,int nS,double tP){
    if(orderSize == 1)
        obj[0].setData(oN, tN, dN, nS, tP);
    else{
        OrderList* temp_obj = new OrderList[orderSize];
        for(int i = 0; i < orderSize - 1; i++)
            temp_obj[i] = obj[i];
        delete[] obj;
        obj = temp_obj;
        obj[orderSize - 1].setData(oN, tN, dN, nS, tP);
    }
    orderSize++;
    return obj;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::ReadOnly))
        qWarning("Can't open file for reading");
    QTextStream in(&file);
    while(!in.atEnd()){
        QString dishName = in.readLine();
        QString category = in.readLine();
        double price = in.readLine().toDouble();
        menuList =  addmenu(menuList,dishName,category,price);
    }
    file.close();
}

OrderList* addOrder(OrderList* obj, int oN, int tN, QString dN, int nS, double tP){
    if(orderSize == 1)
        obj[0].setData(oN, tN, dN, nS, tP);
    else{
        OrderList* temp_obj = new OrderList[orderSize];
        for(int i = 0; i < orderSize - 1; i++)
            temp_obj[i] = obj[i];
        delete[] obj;
        obj = temp_obj;
        obj[orderSize - 1].setData(oN, tN, dN, nS, tP);
    }
    orderSize++;
    return obj;
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::ReadOnly))
        qWarning("Can't open file for reading");
    QTextStream in(&file);
    while(!in.atEnd()){
        int orderNumber = in.readLine().toInt();
        int tableNumber = in.readLine().toInt();
        QString dishName = in.readLine();
        int numberService = in.readLine().toInt();;
        double totalPrice = in.readLine().toDouble();;
        orderList = addOrder(orderList,orderNumber, tableNumber, dishName, numberService, totalPrice);
    }
    file.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    QString dishName = QInputDialog::getText(this,"Enter the dishName: ", "dishName:", QLineEdit::Normal);
    for(int i = 0; i < menuSize - 1; i++){
        if(dishName == menuList[i].returnDishName())
            ui->listWidget->addItem(menuList[i].returnMenu());
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int orderNumber = QInputDialog::getText(this,"Enter order num: "," Order num: ",QLineEdit::Normal).toInt();
    while(!orderNumber){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        orderNumber = QInputDialog::getText(this,"Enter order num: "," Order num: ",QLineEdit::Normal).toInt();
    }
    int tableNumber = QInputDialog::getText(this,"Enter table num:"," Table num: ",QLineEdit::Normal).toInt();
    while(!tableNumber){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        tableNumber = QInputDialog::getText(this,"Enter table num:"," Table num: ",QLineEdit::Normal).toInt();
    }

    int count = 0;

    QString dishName = QInputDialog::getText(this,"Enter dish name:"," Dish name: ",QLineEdit::Normal);
    for(int i =0; i < menuSize-1; i++){
        if(menuList[i].dishName != dishName)
            count++;
         if(count == menuSize-1){
         QMessageBox::critical(ui->centralwidget, "Input error", "This dish isn't on the menu!Check out the menuList");
         dishName = QInputDialog::getText(this,"Enter dish name:"," Dish name: ",QLineEdit::Normal);
        }

    }

    int numberService = QInputDialog::getText(this,"Enter number service:"," Number service: ",QLineEdit::Normal).toInt();
    while(!numberService){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
       numberService =  QInputDialog::getText(this,"Enter number service:"," Number service: ",QLineEdit::Normal).toInt();
    }
    double totalPrice = QInputDialog::getText(this,"Enter total price"," Total price: ",QLineEdit::Normal).toDouble();
    while(!totalPrice){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
       totalPrice = QInputDialog::getText(this,"Enter total price"," Total price: ",QLineEdit::Normal).toDouble();
    }
    orderList = addOrder(orderList,orderNumber, tableNumber,dishName, numberService, totalPrice);
}


void MainWindow::on_pushButton_5_clicked() // save Orderlist
{
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::WriteOnly))
        qWarning("Can't open file for reading");
    QTextStream out(&file);
    for(int i = 0; i < orderSize - 1; i++){
        if (!orderList[i].numberService || !orderList[i].orderNumber || !orderList[i].totalPrice){
          QMessageBox::critical(ui->centralwidget, "", "Can't save file");
            qWarning("Can't save file");
        }
        else
       out << orderList[i].orderNumber << "\n" << orderList[i].tableNumber << "\n" <<  orderList[i].dishName << "\n" << orderList[i].numberService << "\n" << orderList[i].totalPrice << "\n";
    }
    file.close();
}

void MainWindow::on_pushButton_6_clicked() //save menu
{
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));;
    if(!file.open(QIODevice::WriteOnly))
        qWarning("Can't open file for reading");
    QTextStream out(&file);
    for(int i = 0; i < menuSize - 1; i++){
         if (!menuList[i].price){
           QMessageBox::critical(ui->centralwidget, "", "Can't save file");
             qWarning("Can't save file");
         }
         else
             out << menuList[i].dishName << "\n" << menuList[i].category << "\n" << menuList[i].price;
    }
    file.close();
}

void MainWindow::inputData(QListWidgetItem *item)
{
    for(int i = 0; i < menuSize - 1; i++){
        if(item->text() == menuList[i].returnMenu()){
            QString dishName = QInputDialog::getText(this,"Enter dishName: ", "dishName:" , QLineEdit::Normal);
            QString category = QInputDialog::getText(this,"Enter category: ", " category:" , QLineEdit::Normal);
            double price = QInputDialog::getText(this,"Enter price: ", " Price:" , QLineEdit::Normal).toDouble();
            menuList[i].setData(dishName,category,price);
        }
    }
    for(int i = 0; i < orderSize - 1; i++){
        if(item->text() == orderList[i].returnList()){
            int orderNumber = QInputDialog::getText(this,"Enter orderNumber: ", " orderNumber:" , QLineEdit::Normal).toInt();
            int tableNumber = QInputDialog::getText(this,"Enter tableNumber: ",  " tableNumber:" , QLineEdit::Normal).toInt();
           QString dishName = QInputDialog::getText(this,"Enter dishName: ", " dishName:" , QLineEdit::Normal);
            int numberService = QInputDialog::getText(this,"Enter category: ", " category:" , QLineEdit::Normal).toInt();
            double totalPrice = QInputDialog::getText(this,"Enter price: ", " TotalPrice:" , QLineEdit::Normal).toDouble();
            orderList->setData(orderNumber,tableNumber,dishName, numberService, totalPrice);
        }
    }
}

Menu* MainWindow::deleteMenu(Menu* obj, int index){
 if(menuSize > 0){
     menuSize--;
     Menu* temp_obj = new Menu[menuSize];
     int j = 0;
     for(int i = 0;i < menuSize ; i++){
         if(i != index){
             temp_obj[j] = obj[i];
             j++;
         }
     }
     delete[] obj;
     obj = temp_obj;
 }
     return obj;
}



void MainWindow::on_pushButton_7_clicked() //delete
{
    QString str = QInputDialog::getText(this,"Enter dishName:", "DishName: " , QLineEdit::Normal);
    for(int i = 0; i < menuSize -1; i++){
        if(str == menuList[i].returnDishName())
            menuList = deleteMenu(menuList,i);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    OrderList temp;
    int min_index = 0;
    OrderList temp_list;
    for(int i = 0; i < orderSize - 2; i++)
    {
        min_index = i;
        for(int j = i+1; j < orderSize-1;j++){
            if(orderList[min_index].returnPrice() < orderList[j].returnPrice())
                min_index = j;
        }
        temp_list = orderList[min_index];
        orderList[min_index] = orderList[i];
        orderList[i] = temp_list;
    }
}


void MainWindow::on_pushButton_9_clicked() ///output data
{
    ui->listWidget->clear();
     for(int i = 0; i < orderSize - 1; i++){
         ui->listWidget->addItem(orderList[i].returnList());
     }
}


void MainWindow::on_pushButton_10_clicked()
{
    QString dishName = QInputDialog::getText(this,"Enter dish name: "," Dish name: ",QLineEdit::Normal);
    QString category = QInputDialog::getText(this,"Enter category: "," Category: ",QLineEdit::Normal);
    double price = QInputDialog::getText(this,"Enter dish price:","Price:",QLineEdit::Normal).toDouble();
    while(!price){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        price = QInputDialog::getText(this,"Enter dish price:","Price:",QLineEdit::Normal).toDouble();
    }
    menuList = addmenu(menuList,dishName, category,price);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->listWidget->clear();
     for(int i = 0; i < menuSize - 1; i++){
         ui->listWidget->addItem(menuList[i].returnMenu());
     }
}


void MainWindow::on_pushButton_12_clicked()
{
    OrderList temp;
    int min_index = 0;
    OrderList temp_list;
    for(int i = 0; i < orderSize - 2; i++)
    {
        min_index = i;
        for(int j = i+1; j < orderSize-1;j++){
            if(orderList[min_index].returnPrice() < orderList[j].returnPrice())
                min_index = j;
        }
        temp_list = orderList[min_index];
        orderList[min_index] = orderList[i];
        orderList[i] = temp_list;
    }
     ui->listWidget->clear();
     ui->listWidget->addItem(orderList[0].returnList());
}


void MainWindow::on_pushButton_13_clicked()
{
     ui->listWidget->clear();
}


void MainWindow::on_pushButton_14_clicked()
{
    OrderList temp1;
    Menu temp;
    int localCount = 0;
    int globalCount = 0;
    for(int i = 0; i < menuSize - 2; i++)
    {
        for(int j = i+1;j < menuSize-1; j++){
              if(orderList[i].returnDishName() == orderList[j].returnDishName())
                  localCount++;
        }
        if(localCount > globalCount){
            globalCount = localCount;
            temp1 = orderList[i];
        }
        else
            localCount  = 0;
    }
    for(int i = 0; i < menuSize-2; i++){
        for(int j = 0; j < menuSize-1; j++){
            if(menuList[i].returnDishName() == orderList[j].returnDishName()){
                temp = menuList[i];
        }
    }
}
    ui->listWidget->clear();
    ui->listWidget->addItem(temp.returnMenu());
}

