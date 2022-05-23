#ifndef BOOK_H
#define BOOK_H
#include <QString>


class Book
{
public:
    Book();
public:
    short regNum;
    QString author;
    QString title;
    short yearPublishing;
    QString publishingHouse;
    short pageNum;
    Book *next, *prev;
};

#endif // BOOK_H
