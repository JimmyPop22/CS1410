#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main(){
   const int N = 200;
   const int min_val = 1;
   const int max_val = 10;
   const double mean = 5.5;
   const double sd = 2.0;

   default_random_engine en;
   normal_distribution<double> dist(mean, sd);

   ofstream out("data.txt");

   for(int i =0; i < N; i++){
    int x = round(dist(en));
    x = max(min_val, min(max_val, x));
    out << x << " ";
   }
 out.close();

cout << "Generated " << N << " numbers in data.text" << endl;

return 0;
}