#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Animal {
  // Attributes : height weight
  // Capabilities: Run Eat
private:
  int height;
  int weight;
  string name;

  static int numOfAnimals;

public:
  int getHeight() { return height; }
  int getWeight() { return weight; }
  string getName() { return name; }
  void setHeight(int cm) { height = cm; }
  void setWeight(int kg) { weight = kg; }
  void setName(string animalName) { name = animalName; }
  
  void setAll(int, int, string);

  Animal();
  Animal(int, int, string);
  ~Animal();

  static int getNumOfAnimals() { return numOfAnimals; }
  void print();
};

int Animal::numOfAnimals = 0;

void Animal::setAll(int cm, int kg, string animalName) {
  this->height = cm;
  this->weight = kg;
  this->name = animalName;
}

Animal::Animal(int cm, int kg, string animalName) {
  this->height = cm;
  this->weight = kg;
  this->name = animalName;
  Animal::numOfAnimals++;
}

Animal::~Animal() {
  cout << "Animal " << this->name << " destroyed" << endl;
}

Animal::Animal() {
  Animal::numOfAnimals++;
}

void Animal::print() {
   cout << "Animal " << this->name
    << " is " << this->height << " cm tall "
    << " and " << this->weight << " kg in weight" << endl;
}

class Dog: public Animal {
private:
  string sound = "Woof";
public:
  string getSound() { return sound; }

  Dog(int, int, string, string);
  Dog();
  void print();
};

Dog::Dog(int height, int weight, string name, string bark):
  Animal(height, weight, name) {
    this->sound = bark;
}

void Dog::print() {
   cout << "Animal " << this->getName()
    << " is " << this->getHeight() << " cm tall "
    << " and " << this->getWeight() << " kg in weight"
    << " sound " << this->sound << endl;
}

int main() {
  Animal fred;
  fred.setHeight(10);
  fred.setWeight(20);
  fred.setName("Fred");
  fred.print();

  Animal tom(15, 30, "Tom");
  tom.print();

  Dog spot(20, 10, "Spot", "woofff");
  cout << spot.getSound() << endl;
  spot.Animal::print();

  cout << Animal::getNumOfAnimals() << endl;
}

// g++ -std=c++11 classtut.cpp