#include <iostream>  //InputOutput stream. allows std::cout, std::cin, std::endl;
#include <sstream>   //string stream, lets strings behave like input output streams. similar to cin, cout
#include <array>    //Access to arrays, fixed size. 
#include <vector>   //Gives acces to Vector, dynamic arary that can grow or shrink.
#include <string>  // Gives string class. 
#include <limits> //reddit help forum, give info on numeric limits of fundamental types.
#include <algorithm> //gives access to a ton of useful functions
#include <random>  // gives access to a random number generator. Uses mt19937 rng(rd)), uniform_int distribution<int> dist(1, 6)

using namespace std; 
//Define the functions, 6 sided dice using arrays. 

enum class Side { // Lists the sides of a die Side s = Side::Three represent the 3 side of the die.
  One, Two, Three, Four, Five, Six };

struct HistBar {    //stores how many times the die landed on a side. Label stores which side the count represents. 
  int count;
  Side label;
};

int sideToNumber(Side s) {  //converts a sidetonumber evaluation to 1 to 6. Essentially adds, +1 to memory so array starts at 1 instead of 0. 1 =1. 
  return static_cast<int>(s) + 1; //1 = 0 so +1 = 1 to 6
}

// void rollDice(HistBar h[], int n = 1);
//void rollDice(array<HistBar, 6>& h, mt19937&rng);

void rollDice(array<HistBar, 6>& h, mt19937& rng) { //Function that "rolls the dice" Using & lets the cont persist amongst rolls. 
  uniform_int_distribution<int> dist(0, 5);  //random roll, creates the 6 sided dice. int idx generates a random number between 0 and 5. 
  int idx = dist(rng);
  ++h[idx].count; //++h idx accesses the histogram, .count increases the counter by 1 for that side. 
  cout << "You rolled: " << sideToNumber(h[idx].label) << endl; //h[idx] is the Side enum. sTN converts 0-5 to 1-6. cout prints which number was rolled. 
}

//void displayHistogram(const array < HistBar, 6>& h,  char c = '*');

void displayHistogram(const array<HistBar, 6>& h, char c = '*') { //void no value, just prints. const array<HistBar takes a constand referce to the histogram array. const cannot change histogram counts. & passes reference to avoid copying the array.
  cout << "\nHistogram: \n"; //prints the histogram with a new line above and below. 
  for (size_t i = 0; i < h.size(); i++) { //Loops through all six sides of the die. 
    int num = sideToNumber(h[i].label); //converts enum to die number, prints the following 1:, 2: etc. 
    cout << num << ": "; 
    if (h[i].count > 0) { //count how many times the side has been rolled, creates a string of length count with char *. If count is 3 print ***
      cout << string(h[i].count, c);
    }
    cout <<  " " << h[i].count << endl; //After *'s prints the number for visual clarity. 
  }
  cout << "_______________________________________________________"; //Just adds a new line for cleanliness. 
}

//void resetHistogram(array<HistBar, 6>& h);

void resetHistogram(array<HistBar, 6>& h) {   //array<HistBar reference to histogram array. & means modify the OG array. Note:No const here becasue we want to change the counts. 
  for (auto& bar : h) {  // reference each element in the array, auto lets the compiler deduce the type. instead of Histbar&.
    bar.count = 0; //resets the count of that side to 0
  }
  cout << "Histogram has been reset." << endl;
}

int main() {
   random_device rd;   //initializes the random number generator. Modern way to use RNG, better than rand(). 
   mt19937 rng(rd());

   array<HistBar, 6> hist;  //Declare histogram array. Creates an array of 6 HistBar structs.
   for (size_t i = 0; i < hist.size(); i++) { //this initializes each histogram bar.
     hist[i].count = 0; //Ensure the histogram starts at 0. 
     hist[i].label = static_cast<Side>(i);  //changes the array from starting at 0 to starting at 1. Side::One = 1
   }

    bool running = true;

    while (running) { //Allows the program to keep running until user chooses to quit. 
     cout << "Enter your choice\n"
          << "1 Roll Dice\n"
          << "2 Display Histogram\n"
          << "3 Reset Histogram\n"
          << "4 Quit Program\n"
          << "Choice: ";

     int choice; 
     if (!(cin >> choice)) { //This is safety, ensures whatever is entered matches the cirteria and ignores if not. 
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input, please select 1, 2, 3, or 4.\n\n";
         continue;
     }
    
    switch (choice) { //Handles the user choice, 1 through 4. 
        case 1: 
          rollDice(hist, rng);  //1 calls rollDice functions which generates a random 0 to 5 number. Increments the histogram and prints teh rolled number.
          break;
        case 2:
        displayHistogram(hist); //2 calls displayHistogram, loops through all HistBars and prints the side number 1 to 6 and stars *
         break;
        case 3:
         resetHistogram(hist); //3 resets the histogram to 0
        break;
        case 4:  //quits the program
        cout << "Quitting program, goodbye! \n";
        running = false;
        break;
        default: //Ensures return if the user inputs an incorrect value. 
         cout << "Please choose 1 - 4. \n\n";
        }
      } 
      return 0;
    }
    