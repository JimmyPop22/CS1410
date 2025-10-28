#include <iostream>
#include <string>
#include "author.h"
#include "book.h"

using namespace std;



int main(){
  Author a ("George Orwell", "British");
  Book b ("1984", 1949, a);

  b.show();

    return 0;
}