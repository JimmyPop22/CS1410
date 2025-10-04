#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;

struct Month {
string name;
int days;

};  //REMEMBER ; is needed after end of structures

int main(){
     int year;
   cout<< "Enter current year :";
   cin >> year;

 Month months[] {
    {"January", 31},
    {"February", (year % 4 == 0 ) ? 29 : 28 },
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}
 };

// string months[12] = {
//    "January", "February", "March", "April", "May", "June", 
//    "July", "August", "September", "October", "November", "December"
// };



// int days[12] = {  //year %4 asks what year and devides by 4. If answer is 0 then the value is 28.
//    31, 
//   (year % 4 == 0 ) ? 29 : 28 ,
//    31, 30, 31, 30,
//    31, 31, 30, 31, 30, 31
// };
  cout << setw(10) << "Month" << setw(12) << "# of Days" << endl;
  cout << "________________________________" << endl;
  for(int i = 0; i <12; i++) {
     cout << setw(10) << months[i].name << setw(12) << months[i].days << endl;
  
   }
    return 0;
}