#include <iomanip>
#include <iostream>
#include <array>
#include <string>
using namespace std;


int main(){
  int age;
  string fullName;

  cout << "Enter age:" << endl;
  cin >> age;

  cin.ignore();

  cout << "Enter Full Name" << endl;
  getline(cin, fullName);

  cout << "Hello! You are " << age << " years old and your full name is "
    << fullName << endl;

return 0;
}