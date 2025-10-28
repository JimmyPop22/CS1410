#ifndef __BOOK_H__
#define __BOOK_H__
#include "author.h"
#include <string>
#include <iostream>

class Book {
private:
  std::string title;
  int year;
  Author author;

public:
  Book(const std::string& t, int y, const Author& a):title(t), year(y), author(a){}
  std::string getTitle() const {return title;}
  int getYear() const {return year;}
  Author getAuthor() const {return author;}

  void setTitle(const std::string& t){title = t;}
  void setYear(const int& y){year = y;}
  void setAuthor(const Author& a){author = a;}

  void show() const{
    std::cout << "Book" << title << "(" << year << ")/n"
    << "Author : " << author.getName() << "[" << author.getNationality() << "]" << std::endl;

  }

};

  #endif;