#include "tree.h"

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    root = makeEmpty(root);
}

void Tree::insert(QString surname, QString name, QString patronymic, QString passportID) {
    root = insert(surname, name, patronymic,passportID, root);
}

void Tree::removeNode(QString surname) {
    root = remove(surname, root);
}

void Tree::removeAll()
{
    root = makeEmpty(root);
}


    QString Tree::search(QString surname) {
    root = find(root, surname);
    QString answer;
    if(root != nullptr)
        answer =  "Surname: " + root->surname + "\n" + "Name: " + root->name + "\n" + "Patronymic: " + root->patronymic + "\n" + "PassportID: " + root->passportID;
    else
        answer = "Person not found";
    return answer;

}

int Tree::totalLevel(){
    return height(root);
}


void Tree::disp(int level,QString &vizual)
{
    Display(level,root,vizual);
}

void Tree::preorderPrint(QString &output) {
    traversePreOrder(root,output);
}

void Tree::inorderPrint(QString &output) {
    traverseInOrder(root,output);
}

void Tree::postorderPrint(QString &output) {
    traversePostOrder(root,output);
}

unsigned int Tree::task(int level){
    return  printGivenLevel(root,level);
}
