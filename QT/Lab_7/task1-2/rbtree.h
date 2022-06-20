#ifndef RBTREE_H
#define RBTREE_H

#include<iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};
template<class T>
struct RBTreeNode
{
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;

    T _data;
    Color _color;
    RBTreeNode(const T& data)
            :_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
            ,_data(data)
            ,_color(RED)
    {}
};
template<class T,class Ref,class Ptr>
struct _TreeIterator
{

    typedef RBTreeNode<T> Node;//тип узла
    typedef _TreeIterator<T, Ref, Ptr> Self;//тип прямого итератора
    Node* _node;//инкапсулированный указатель
    _TreeIterator(Node* node)
            :_node(node)
    {}
    Ref operator*()
    {
        return _node->_data;
    }
    Ptr operator ->()
    {
        return &_node->_data;
    }
    bool  operator !=(const Self& s) const
    {
        return _node != s._node;
    }
    bool  operator ==(const Self& s) const
    {
        return _node == s._node;
    }
    Self& operator++()
    {
        if (_node->_right)
        {
            Node* left = _node->_right;
            while (left->_left)
            {
                left = left->_left;
            }
            _node = left;
        }
        else
        {
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_right)
            {
                cur = cur->_parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }
    Self& operator--()
    {
        if (_node->_left)
        {
            Node* right = _node->_left;
            while (right->_right)
            {
                right = right->_right;
            }
            _node = right;
        }
        else
        {
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_left)
            {
                cur = cur->_parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }
};
template<class K, class T, class KeyOfT>
class RBTree
{
    typedef RBTreeNode<K> Node;
public:
    RBTree()
            :_root(nullptr)
    {}
    typedef _TreeIterator<T, T&, T*> iterator;
    iterator begin()
    {
        Node* left = _root;
        while (left && left->_left)
        {
            left = left->_left;
        }

        return iterator(left);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    pair <iterator, bool>insert(const T& data)
    {
        //1. Дерево пустое
        if (_root == nullptr)
        {
            _root = new Node(data);
            _root->_color = BLACK;//Корневой узел черный
            return make_pair(iterator(_root), true);
        }

        KeyOfT  koft;
        //2.Дерево не пустое
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            //Ключ нового узла больше, чем текущий узел справа
            if (koft(cur->_data) < koft(data))
            {
                parent = cur;
                cur = cur->_right;
            }
                //Новый ключ узла меньше, чем текущий узел слева
            else if (koft(cur->_data) > koft(data))
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return make_pair(iterator(cur), false);
            }
        }
        cur = new Node(data);
        Node* newnode = cur;
        newnode->_color = RED;
        if (koft(parent->_data) < koft(data))
        {
            parent->_right = newnode;
            newnode->_parent = parent;
        }
        else
        {
            parent->_left = newnode;
            newnode->_parent = parent;
        }

        //Настройка цветов
        while (parent && parent->_color == RED)
        {
            Node* grandParent = parent->_parent;
            if (grandParent->_left == parent)
            {
                Node* uncle = grandParent->_right;
                //Дядя существует и красный, отец и дядя оба черные
                //Предки настроены на красный цвет, если нет, изменились черные узлы каждого пути.
                if (uncle && uncle->_color == RED)
                {
                    parent->_color = BLACK;
                    uncle->_color = BLACK;
                    grandParent->_color = RED;
                    //продолжаем идти вверх
                    cur = grandParent;
                    parent = cur->_parent;
                }
                else //Дядя не существует или дядя существует и черный
                {
                    if (parent->_left == cur)
                    {
                        RotateR(grandParent);
                        parent->_color = BLACK;
                        grandParent->_color = RED;
                    }
                    else
                    {
                        RotateL(parent);
                        RotateR(grandParent);
                        grandParent->_color = RED;
                        cur->_color = BLACK;
                    }
                    break;
                }
            }
            else //родитель - левый ребенок grandParent
            {
                Node* uncle = grandParent->_left;
                if (uncle && uncle->_color == RED)
                {
                    uncle->_color = BLACK;
                    parent->_color = BLACK;
                    grandParent->_color = RED;
                    cur = grandParent;
                    parent = cur->_parent;
                }
                else
                {
                    if (parent->_right == cur)
                    {
                        RotateL(grandParent);
                        parent->_color = BLACK;
                        grandParent->_color = RED;
                    }
                    else
                    {
                        RotateR(parent);
                        RotateL(grandParent);
                        cur->_color = BLACK;
                        grandParent->_color = RED;
                    }
                    break;
                }
            }
        }
        _root->_color = BLACK;
        return make_pair(iterator(newnode), true);
    }
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        Node* parentParent = parent->_parent;
        //Начальный поворот
        parent->_right = subRL;
        subR->_left = parent;

        parent->_parent = subR;
        //изменение родительского узла
        if (subRL)
            subRL->_parent = parent;
        if (_root == parent)
        {
            _root = subR;
            _root->_parent = nullptr;
        }

        else
        {
            //После поворота subR может быть два случая левого и правого поддеревьев.
            if (parentParent->_left == parent)
                parentParent->_left = subR;
            else
                parentParent->_right = subR;
            subR->_parent = parentParent;
        }
    }
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* parentParent = parent->_parent;//запись родительского узла родителя
        parent->_left = subLR;
        subL->_right = parent;
        // Обновить родителя двух узлов, которые перемещаются одновременно
        //subLR также может быть пустым узлом
        if (subLR)
            subLR->_parent = parent;
        parent->_parent = subL;
        //родителем может быть отдельное дерево или поддерево, в зависимости от ситуации
        if (_root == parent)
        {
            _root = subL;
            _root->_parent = nullptr;
        }

        else
        {
            //Возможно, что родителем является поддерево, и это может быть левое поддерево.
            if (parentParent->_left == parent)
                parentParent->_left = subL;
            else
                //также может быть правым поддеревом
                parentParent->_right = subL;
            //Настройка родительского узла subL
            subL->_parent = parentParent;
        }
    }
    void Destory(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        Destory(root->_left);
        Destory(root->_right);
        delete root;
    }

    ~RBTree()
    {
        Destory(_root);
        _root = nullptr;
    }

    iterator Find(const K& key)
    {
        KeyOfT koft;
        Node* cur = _root;
        while (cur)
        {
            if (koft(cur->_data) > key)
            {
                cur = cur->_left;
            }
            else if (koft(cur->_data) < key)
            {
                cur = cur->_right;
            }
            else
            {
                return iterator(cur);
            }
        }

        return end();
    }

    bool _CheckBlance(Node* root,int blackNum, int count)
    {
        if (root == nullptr)
        {
            if (count != blackNum)
                return false;
            return true;
        }

        if (root->_color == RED && root->_parent->_color == RED)
            return false;
        if (root->_color == BLACK)
        {
            count++;
        }

        return _CheckBlance(root->_left, blackNum, count)
               && _CheckBlance(root->_right, blackNum, count);
    }

    bool CheckBlance()
    {
        if (_root == nullptr)
            return true;

        if (_root->_color == RED)
            return false;

        int blackNum = 0;
        Node* left = _root;
        while (left)
        {
            if (left->_color == BLACK)
            {
                blackNum++;
            }

            left = left->_left;
        }

        int count = 0;
        return _CheckBlance(_root, blackNum, count);
    }

    /*void _InOrder(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        _InOrder(root->_left);
        cout << root->_kv.first << ":"<<root->_kv.second<<endl;
        _InOrder(root->_right);
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }*/

private:
    Node* _root;
};

#endif // RBTREE_H
