#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std; 

/*
 * A class representing courses
 * define a custom class with 5 private data members. Pick any concept, book, car, employee data.
 * LETS DO CARS. 
 * Model after "Course" code below. 
 * Four constructors. Different ways to initialize a class. 
 * Destructors for constructors. Similar to Ex07. 
 * Accessor One Public function for each private data member that allows external code to read the value of that member. 
 * Mutators same as Accessors. 
 * str() returns a string that provides a formatted summary of all data members. 
 */
class Car {
private:
  string make;      // Toyota
  string model;     // Tundra
  int mileage;      // 10,000 miles 
  int year;         // 2022
  string color;     // Charcoal 

public:
  // Constructors
  Car() : make(""), model(""), mileage(0), year(0), color("") {} //Default parameter constructor

  //Two parameter
  Car(string carMake, string carModel) : make(carMake), model(carModel), mileage(0), year(0), color(""){}
  
  //Three parameter 
  Car(string carMake, string carModel, int carMileage) : make(carMake), model(carModel), mileage(carMileage), year(0), color(""){}

  //Four parameter
  Car(string carMake, string carModel, int carYear, string carColor) : make(carMake), model(carModel), mileage(0), year(carYear), color(carColor){} 

//Five parameter  
  Car(string carMake, string carModel, int carMileage, int carYear, string carColor) : make(carMake), model(carModel), mileage(carMileage), year(carYear), color(carColor) {}
	  
  // Destructor
  ~Car() {}

  // Accessors and mutators
  // Make
  const string& getMake() const {
    return make;
  }
  void setMake(const string& carMake) {
    make = carMake;
  }

  // MODEL
  const string& getModel() const {
    return model;
  }
  void setModel(const string& carModel) {
    model = carModel;
  }

  // MILEAGE
  int getMileage() const {
    return mileage;
  }
  void setMileage(int carMileage){
    mileage = carMileage;
  }

  // Year
  int getYear() const {
    return year;
  }
  void setYear(int carYear) {
    year = carYear;
  }

  // Color
  const string& getColor() const {
    return color;
  }
  void setColor(const string& carColor) {
    color = carColor;
  }

  // Prints course info
  string str() const {
    stringstream sout;
    sout << "         Make: " << make << endl
         << "        Model: " << model << endl
         << "      Mileage: " << mileage << endl
         << "         YEAR: " << year << endl
         << "        Color: " << color << endl;
    return sout.str();
  }
};

# endif

//Do I add the main file to this?
int main() {
  // Create three objects statically (in the stack)
  Car car1;
  car1.setMake("Toyota");
  car1.setModel("Tundra");
  car1.setMileage(10000);
  car1.setYear(2020);
  car1.setColor("Charcoal");

  Car car2("Toyota", "Tacoma");
  car2.setMileage(40000);
  car2.setYear(2022);
  car2.setColor("Burnt Orange");

  Car car3("GMC", "Denali HD", 350000);
  car3.setYear(2014);
  car3.setColor("Black");

  Car car4("Chevy", "Silverado", 69000, 2019, "Grey");

  // Create three objects dynamically (in the heap)
  Car *car5 = new Car;
  car5->setMake("Toyota");
  car5->setModel("Camry");
  car5->setMileage(10000);
  car5->setYear(2020);
  car5->setColor("White");

  Car *car6 = new Car("Toyota", "Supra");
  car6->setMileage(40000);
  car6->setYear(2022);
  car6->setColor("Cherry Red");

  Car *car7 = new Car("Tesla", "Model S", 5000);
  car7->setYear(2022);
  car7->setColor("Blue");

  Car *car8 = new Car("Nissan", "GTR", 52314, 2016, "Midnight Blue");
  array<Car, 8> all_cars{car1, car2, car3, car4, *car5, *car6, *car7, *car8};

  // Print all courses	
  cout << "Display all my cars:" << endl;
  for(const auto& c : all_cars) {
    cout << c.str() << endl;
  }

  delete car5;
  delete car6;
  delete car7;
  delete car8;

  return 0;
}