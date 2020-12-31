#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void youngerByValue(int age){
  cout << age << " -> ";
  age--;
  cout << age << endl;
}

void youngerByRef(int* age){
  cout << *age << " -> ";
  (*age)--;
  cout << *age << endl;
}

void youngerByRef2(int& age){
  cout << age << " -> ";
  (age)--;
  cout << age << endl;
}

int main() {
  int myAge = 30;
  int myAge2 = 40;

  int* myAgePtr = &myAge; // pointer to myAge address

  // https://stackoverflow.com/questions/4629317/what-does-int-mean
  // C does not have &
  int& myAgeRef = myAge; // reference to myAge (not the same as pointer)
  
  cout << "myAge    is type " << typeid(myAge).name() << endl;
  cout << "myAgePtr is type " << typeid(myAgePtr).name() << endl;
  cout << "myAgeRef is type " << typeid(myAgeRef).name() << endl;


  cout << "myAge Address from myAgePtr " << myAgePtr << endl;
  // * dereference
  cout << "myAge Value from *myAgePtr " << *myAgePtr << endl;
  cout << "myAgeRef Value " << myAgeRef << endl;

  youngerByValue(myAge);
  cout << "youngerByValue(myAge) myAge same: " << myAge << endl;

  youngerByRef(&myAge);
  cout << "youngerByRef(&myAge) myAge: " << myAge << endl;

  youngerByValue(*myAgePtr);
  cout << "youngerByValue(*myAgePtr) myAge same: " << myAge << endl;

  youngerByRef(myAgePtr);
  cout << "youngerByRef(myAgePtr) myAge: " << myAge << endl;

  youngerByValue(myAgeRef);
  cout << "youngerByValue(myAgeRef) myAge same: " << myAge << endl;

  youngerByRef(&myAgeRef);
  cout << "youngerByRef(&myAgeRef) myAge: " << myAge << endl;

  youngerByRef2(myAgeRef);
  cout << "youngerByRef2(myAgeRef) myAge: " << myAge << endl;

  cout << "myAge " << &myAge << " is " << myAge << endl;
  cout << "myAge2 " << &myAge2 << " is " << myAge2 << endl;
  cout << "myAgePtr " << myAgePtr << " has value of " << *myAgePtr << endl;
  cout << "reassign myAgePtr to myAge2 does not affect myAge" << endl;
  myAgePtr = &myAge2;
  cout << "myAge " << &myAge << " is now " << myAge << endl;
  cout << "myAgePtr " << myAgePtr << " has value of " << *myAgePtr << endl;

  cout << "myAge " << &myAge << " is " << myAge << endl;
  cout << "myAge2 " << &myAge2 << " is " << myAge2 << endl;
  cout << "myAgeRef " << &myAgeRef << " has value of " << myAgeRef << endl;
  cout << "copy value of myAge2 to myAge using myAgeRef = myAge2" << endl;
  myAgeRef = myAge2;
  cout << "myAge " << &myAge << " is now " << myAge << endl;
  cout << "myAgeRef " << &myAgeRef << " has value of " << myAgeRef << endl;

  int nums[5] = {1, 2, 3, 4, 5};
  int numsSize = sizeof(nums)/sizeof(nums[0]);
  int* numsPtr = nums;
  for(int i = 0; i < numsSize; i++) {
    cout << &nums[i] << " " << nums[i] << endl;
  }

  // &nums or nums is address to the start of the array 
  cout << "nums is type " << typeid(nums).name() << " value is " << nums << endl;
  cout << "&nums       is " << &nums << endl;
  // (&nums + 1) is the address after the end of the array
  cout << "(&nums + 1) is " << (&nums + 1) << endl;

  for(int i = 0; i < numsSize; i++) {
    cout << numsPtr << " " << *numsPtr << endl;
    numsPtr++;
  }
}

// g++ -std=c++11 ptrtut.cpp