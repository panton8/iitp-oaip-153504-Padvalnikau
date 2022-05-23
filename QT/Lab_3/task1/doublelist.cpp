#include "doublelist.h"

DoubleList::DoubleList()
{
    root = new Node;
       length = 0;
}

DoubleList::~DoubleList() {}

void DoubleList::add(int numb)
{
    SharedPtr<Node> newel = SharedPtr<Node>(new Node);
    newel->data = numb;
    if (this->getLength() == 0) {
        root->next = newel;
        newel->prev = newel;
        newel->next = newel;
        this->length++;
        return;
    } else {
        int pos = this->getLength();
        SharedPtr<Node> current = root->next;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        newel->next = current;
        newel->prev = current->prev;
        (current->prev.lockW())->next = newel;
        current->prev = newel;
        this->length++;
        return;
    }
}

void DoubleList::popback()
{
    if (this->getLength() == 0)
    {
        return;
    }
    else
    {
        if (this->getLength() == 1)
        {
            this->root->next = SharedPtr<Node>();
            this->length--;
        }
        else
        {
            int pos = this->getLength();
            SharedPtr<Node> deletenode = root->next;
            for (int i = 0; i < pos; i++)
            {
                deletenode = deletenode->next;
            }
            (deletenode->prev.lockW())->next = deletenode->next;
            deletenode->next->prev = deletenode->prev;
            this->length--;
        }
    }
}

int DoubleList::getLength()
{
    return this->length;
}

int DoubleList::getData(int pos)
{
    SharedPtr<Node> current = root->next;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }

    return current->data;
}

void DoubleList::insert(int pos, int numb)
{
    SharedPtr<Node> nodeinsert = SharedPtr<Node>(new Node);
    nodeinsert->data = numb;

    if (this->getLength() == 0)
    {
        root->next = nodeinsert;
        nodeinsert->prev = nodeinsert;
        nodeinsert->next = nodeinsert;
        this->length++;
        return;
    }
    if (pos == 0)
    {
        nodeinsert->prev = root->next->prev;
        nodeinsert->next = root->next;
        (root->next->prev.lockW())->next = nodeinsert;
        root->next->prev = nodeinsert;
        root->next = nodeinsert;
        this->length++;
        return;
    }
    else
    {
        SharedPtr<Node> current = root->next;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }

        nodeinsert->next = current;
        nodeinsert->prev = current->prev;
        (current->prev.lockW())->next = nodeinsert;
        current->prev = nodeinsert;
        this->length++;
        return;
    }
}

void DoubleList::erase(int pos)
{
    if (this->getLength() == 0)
    {
        return;
    }
    else
    {
        if (this->getLength() == 1)
        {
            this->root->next = SharedPtr<Node>();
            this->length--;
        }
        else
        {
            SharedPtr<Node> deletenode = root->next;
            for (int i = 0; i < pos; i++)
            {
                deletenode = deletenode->next;
            }
            (deletenode->prev.lockW())->next = deletenode->next;
            deletenode->next->prev = deletenode->prev;
            this->length--;
        }
    }
}
