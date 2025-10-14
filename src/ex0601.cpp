#include <iostream> //Allows user input, cin cout
using namespace std; //gets rid of std necessity


void reduce_balance(int* p, int by){
  *p = *p - by;
}
int main(){
  int balance = 85;
  int* ptr = &balance; //asterisk indicates pointing to an int. & extracts address where balance is stored in memory
  cout << balance << endl << ptr << endl;

  int w =15;
  reduce_balance(ptr, w);
  cout << balance << endl;

  int* dbalance = new int;
  *dbalance = 100;

  cout << *dbalance << endl; //prints the value
  cout << dbalance << endl; //prints the address

  delete dbalance; //have to place or will have memory leak

    return 0;
}