# include <iostream> //Gives cout and cin

using namespace std; //gets rid of std neccessity. 



int main(){
  int bills[] {10, 20, 50};
  int* p = bills;

  cout << *p << "," << *(p+1) << "," << *(p+2) << endl;
  bills[2] = 100;
  *(p+2) = 100;

  int* dbills = new int[3]{10,20,50}; //dunamic array 
   cout << *dbills << "," << *(dbills+1) << "," << *(dbills+2) << endl;
   cout << dbills[0] << "," << dbills[1] << "," << dbills[2] << endl;
   
 delete[]dbills;
    return 0;
}