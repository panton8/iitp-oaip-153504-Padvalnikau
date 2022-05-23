#pragma once

#ifndef PARSER_H
#define PARSER_H

#pragma once

#include <string.h>
#include <vector>
#include <string>
#include <iostream>

#include "vector"
#include "stack.h"
#include <QString>
#include "pair.h"
#include <Mystring.h>

class parser {
private:
    const char* input;

    MyString token;

    //один string хранит имя переменной, второй значение по умолчанию

    vector< std::pair<MyString, MyString> >  shorts, ints, unsigneds,
                                    doubles,
                                    chars, strings,
                                    bools, vectors;

    //первый string: тип данных для указателя, std::pair <string, string> - см. выше

    vector<std::pair <MyString, std::pair<MyString, MyString>> > pointers;

    MyString ptr_type;

    unsigned line = 1;

    //unsigned отвечает за номер строки для вывода перегруженных функций
    vector< std::pair<unsigned, MyString> > functions;

    MyString prototype;


    unsigned classes = 0, structs = 0, arrs = 0,
        overloaded = 0, local_variables = 0, ifs = 0;

    //завести стек скобок {, если стек пустой, то у нас глобальные переменные
    //когда встречаем }, убираем верхний элемент стека
    //

    Stack<char> skobki;


    /*
        логические ошибки: завести вектор констант,
        если встречается while(const) / while(true) / while (false) /
        while (1) / while (0) - логическая ошибка на строке

        а лучше проверять while и затем выражение в скобках:
        если там 1/0/true/false то ошибка, иначе если там константа тоже ошибка

        не только единица, но и любое другое число

        проверка на константу: считать имя переменной и поискать его в
        векторе констант

    */

    //string - имя константы
    vector<MyString> consts;

    QString info;

    MyString parse_token();

     void add_func();

    void get_overloaded();

    void add_ptr();

    void add_item(vector <std::pair<MyString, MyString>>& variables);

    void add_vector();

    void str_vec_changed(MyString& token);

    void add_if();

    void find_changed(char operation);

    void push_const(vector< std::pair<MyString, MyString> > &variables, unsigned& sz) ;

   void push_const_ptr(unsigned& sz);

    void add_const();

    bool is_num(MyString& str);

   void check_while() ;

    void increment();

    void find_changed_CIN();

    void parse_code();

   void show_variables(vector<std::pair<MyString, MyString>>& variables);

   void show_ptr();

   void show_func() ;

public:
    explicit parser(const char* code) : input(code) {}

    ~parser() = default;

    void parse() ;

   QString get_info() ;
};

#endif // PARSER_H
