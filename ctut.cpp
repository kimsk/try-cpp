#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
  cout << "Hello World!" << endl;

  const double PI = 3.1415926535;

  char myGrade = 'A';

  bool isHappy = true;
  
  int myAge = 39;

  float favNum = 3.141592;

  double otherFavNum = 1.23456789;

  cout << "Favorite Number: " << favNum << endl;
  cout << "Size of int " << sizeof(myAge) << endl;

  int five = 5;

  cout << "5++ = " << five++ << endl;
  five = five - 1;
  cout << "++5 = " << ++five << endl;

  cout << "1 + 2 * (10 - 3)/7 = " << 1 + 2 * (10 - 3)/7 << endl; 
  cout << "4/5 = " << (float) 4/5 << endl;

  int favNums[5] = {1, 2, 3, 4, 5};
  cout << "favNums[2] = " << favNums[2] << endl;

  int randNum = (rand() % 100) + 1;

  while (randNum != 100) {
    cout << randNum << ", ";
    randNum = (rand() % 100) + 1;
  }

  string yourName;
  cout << endl << "what is your name? ";
  getline(cin, yourName);
  cout << "hello " << yourName << " (size: " << yourName.size() << ")" << endl;

  cout << "yourName.assign(yourName, 0, 2) " << yourName.assign(yourName, 0, 2) << endl;


  vector <int> vectorNums(5);
  vectorNums.insert(vectorNums.begin(), favNums, favNums+2);
  cout << vectorNums[0] << endl;

  string kkQuote = "the best thing money can buy is the financial freedom!";

  ofstream writer("fire.txt");

  if (!writer) {
    cout << "Error openning file" << endl;
    return -1;
  } else {
    writer << kkQuote << endl;
    writer.close();
  }

  ofstream writer2("fire.txt", ios::app);
  if (!writer2) {
    cout << "Error openning file" << endl;
    return -1;
  } else {
    writer2 << kkQuote << endl;
    writer2.close();
  }

  char letter;
  ifstream reader("fire.txt");
  if(!reader) {
    cout << "Error openning file" << endl;
    return -1; 
  } else {
    for(int i = 0; !reader.eof(); i++){
      reader.get(letter);
      cout << letter;
    }
    reader.close();
  }
  return 0;
}

// g++ -std=c++11 ctut.cpp