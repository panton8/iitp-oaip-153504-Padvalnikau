#ifndef TREE_H
#define TREE_H
#include <QString>
#include <QListWidget>
 using namespace std;

class Tree
{
    struct node
    {
        QString surname;
        QString name;
        QString patronymic;
        QString passportID;
        node* left;
        node* right;
        int height;
    };

    node* root;

    int heightForTask(node* root) { //Функция определения высоты дерева (число уровней)
        if (root == NULL) {
            return 0;
        } else {
            int lheight = heightForTask(root->left);
            int rheight = heightForTask(root->right);
            if (lheight > rheight) {
                return (lheight + 1);
            } else {
                return (rheight + 1);
            }
        }
    }

    bool isLeaf(node* root) { //Функция проверки, что узел дерева является листом
        if (!root->left && !root->right) {
            return true;
        }
        return false;
    }

    int printGivenLevel(node* root, int level) { //Функция подсчета листьев на заданном уровне
        if (root == nullptr)
            return 0;
        static int k = 0;
        if (level == 1) {
            if (isLeaf(root)) {
                k++;
            }
        }
        else if (level > 1) {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
        return k;
    }


    node* makeEmpty(node* t) {
        if(t == nullptr)
            return nullptr;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return nullptr;
    }

    node* insert(QString surname,QString name,QString patronymic,QString passportID, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->surname = surname;
            t->name = name;
            t->patronymic = patronymic;
            t->passportID = passportID;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(surname < t->surname)
        {
            t->left = insert(surname,name,patronymic,passportID, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(surname < t->left->surname)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(surname > t->surname)
        {
            t->right = insert(surname,name,patronymic,passportID, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(surname > t->right->surname)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* find(node* root, QString surname)
    {
        // Base Cases: root is null or key is present at root
        if (root == nullptr  || root->surname == surname)
            return root;

        // Key is greater than root's key
        if (root->surname < surname)
            return find(root->right, surname);

        // Key is smaller than root's key
        return find(root->left, surname);
    }

    node* remove(QString surname, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

            // Searching for element
        else if(surname < t->surname)
            t->left = remove(surname, t->left);
        else if(surname > t->surname)
            t->right = remove(surname, t->right);

            // Element found
            // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->surname = temp->surname;
            t->right = remove(t->surname, t->right);
        }
            // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = std::max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
                // right left case
            else
                return doubleLeftRotate(t);
        }
            // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
                // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    // Прямой обход дерева
    void traversePreOrder(node *temp,QString &output) {
        if (temp != nullptr) {
            output +=  temp->surname + "\n";
            traversePreOrder(temp->left,output);
            traversePreOrder(temp->right,output);
        }
    }

    // Центрированный обход дерева
    void traverseInOrder(node *temp,QString &output) {
        if (temp != nullptr) {
            traverseInOrder(temp->left,output);
            output +=  temp->surname + "\n";
            traverseInOrder(temp->right,output);
        }
    }

    // Обратный обход дерева
    void traversePostOrder(node *temp,QString &output) {
        if (temp != nullptr) {
            traversePostOrder(temp->left,output);
            traversePostOrder(temp->right,output);
            output +=  temp->surname + "\n";
        }
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void Display(int level, node *ptr,QString &vizual)
    {
        int i;
        if (ptr != NULL)
        {
            Display(level + 1, ptr->right,vizual);
            vizual += "\n";
            if (ptr == root)
                vizual += "Root -> ";
            for (i = 0; i < level && ptr != root; i++)
                vizual +=  "        ";
            vizual += ptr->surname;
            Display(level + 1, ptr->left,vizual);
        }
    }

public:
    Tree();

    ~Tree();

    void insert(QString surname, QString name, QString patronymic, QString passportID);

    void disp(int level,QString &vizual);

    void removeNode(QString surname);

    void removeAll();

    QString search(QString surname);

    int totalLevel();

    void preorderPrint(QString &output);

    void inorderPrint(QString &output);

    void postorderPrint(QString &output);

    unsigned int task(int level);
};

#endif // TREE_H
