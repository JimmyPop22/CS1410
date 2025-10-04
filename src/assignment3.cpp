//structures and enumerations

// CS1410 - Assignment 03
#include <iostream>
#include <iomanip>
#include <cmath>  
#include <string>
using namespace std;


//TODO 1: ShapeKind Enumeration goes here
enum class ShapeKind {    //You did this right
Circle, 
Square, 
Rectangle
};

//TODO 2: Shape Structure goes here
 struct Shape{
  ShapeKind kind; //Recall the enum class to define shape type 
  double length;
  double width; 
};

// Function prototypes and definitions
 double area(Shape s) {//s is the parameter passed into the function. 
//TODO 3: area() definition goes here

  if (s.kind == ShapeKind::Circle) {
    double r = s.length / 2.0;
  return M_PI * r * r;
  }
  else if (s.kind == ShapeKind::Square) {
  return s.length * s.width;
  }
  else if (s.kind == ShapeKind::Rectangle) {
  return s.length * s.width;
  }  
    return 0.0;
}
 
 //TODO 4: perimeter() definition goes here
 
double perimeter(Shape s) {

 if (s.kind == ShapeKind:: Circle) {
   double r = s.length / 2.0;
   return 2 * M_PI * r;
  }
 else if (s.kind == ShapeKind::Square) {
  return 4 * s.length;
  } 
 else if (s.kind == ShapeKind::Rectangle){
   return 2 * (s.length + s.width);
  }
  return 0.0;
}
 
string nameOf(Shape s) {
//TODO 5: nameOf() definition goes here

if (s.kind == ShapeKind::Circle){
   return "Circle";
   }
 else if (s.kind == ShapeKind::Square){
   return "Square";
   } 
 else if (s.kind == ShapeKind::Rectangle){
   return "Rectangle";
   }
   return "Unknown";
}
//void promptAndReadInputFor(Shape&);
//TODO 6: promptAndReadInputFor() definition goes here
void promptAndReadInputFor(Shape& shape) {
 if (shape.kind == ShapeKind::Circle) {
  double diameter;
  cout << "Enter the diameter of the Circle: ";
  cin >> diameter;
  shape.length = diameter;
  shape.width = diameter;
 }
 else if (shape.kind == ShapeKind::Square){
  double side;
  cout << "Enter the side length of the Square : ";
  cin >> side;
  shape.length = side;
  shape.width = side;
 }
 else if (shape.kind == ShapeKind::Rectangle){
 double len, wid;
 cout << "Enter the length of the rectangle :";
 cin >> len;
 cout << "Enter the width of the rectangle :";
 cin >> wid;
 
 shape.length = len;
 shape.width = wid;
 
 if (len == wid) {
 shape.kind = ShapeKind::Square;
  cout << "Length and Width are equal, shape changed to Square." << endl;
  
  }
 }
}





// The main function
int main() {
  // Shape objects
  Shape circle = {ShapeKind::Circle, 0.0, 0.0 };
 //TODO 7: define two more shape objects: a square and and a rectangle 
  Shape square = {ShapeKind::Square, 0.0, 0.0 };
  Shape rectangle = {ShapeKind::Rectangle, 0.0, 0.0 };
 //TODO 8: Call the promptAndReadInputFor() function on each of the above three shapes
 
  promptAndReadInputFor(circle);
  promptAndReadInputFor(square);
  promptAndReadInputFor(rectangle);
  
  //TODO 9: Print a out a report of these shapes in a table-like format
  cout << fixed << setprecision(2);
  cout << "\nYou enterered:\n";
  cout << left << setw(12) << "Shape"
       << setw(12) << "Length"
       << setw(12) << "Width"
       << setw(12) << "Area"
       << setw(12) << "Perimeter" << "\n";
  cout << string(60, '_') << "\n";
 Shape shapes[] = { circle, square, rectangle };
for (const auto &s : shapes) {
  cout << left << setw(12) << nameOf(s)
       << setw(12) << s.length
       << setw(12) << s.width
       << setw(12) << area(s)
       << setw(12) << perimeter(s)
       << "\n";
}


  return 0;
   }
  
  
