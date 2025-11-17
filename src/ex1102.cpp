#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
   ifstream in("data.txt");
   vector<int> data;
   int x;
   while(in >> x){
       data.push_back(x);
   }
   in.close();

   //min and max
   int min_val = *min_element(data.begin(), data.end());
   int max_val = *max_element(data.begin(), data.end());

   double sum = 0.0;
   for(int x : data){
    sum += x;
   }

   double mean = sum/ data.size();

   double var = 0.0;
    for(int x : data){
    var  += (mean - x) * (mean - x);
   }

   var = var/data.size();
   double sd = sqrt(var);

   //Histogram
   vector<int> freq(11,0);
   for (int x : data){
      if(x >= 1 && x <= 10){
        freq[x]++;
      }
   }

   cout << "\nHistogram (1 to 10):\n";
    for(int i =1; i <=10; i++){
        cout << setw(2) << i << " | ";
        int bar_length = freq[i] / 2;
        for(int j = 0; j < bar_length; j++){
            cout << "*";
        }
        cout << "(" << freq[i] << ")\n" << endl;
    }

    //Summary
    cout << fixed << setprecision(2);
    cout << "\n\nSummary:\n";
    cout << "count:" << data.size() << endl;
    cout << "Min: " << min_val << endl;
    cout << "Max: " << max_val << endl;
    cout << "Mean: " << mean << endl;
    cout << "StdDev: " << sd << endl;
   return 0;
}