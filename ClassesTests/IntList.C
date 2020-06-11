#include <iostream>
#include <stdio.h>
#include "IntList.h"

IntList::IntList() {
  Items = new int[SIZE];
  numItems = 0;
  arraySize = SIZE;
}

IntList::IntList(int v, int n) {
  Items = new int[SIZE];
  numItems = 0;
  arraySize = SIZE;
  for(int i = 0; i < n; i++)
    this->AddToEnd(v);
}

void IntList::AddToEnd(int k) {
   if(numItems < arraySize) {
     Items[numItems++] = k;
   } else {
     int *temp = new int[arraySize*2];
     for(int i = 0; i < arraySize; i++)
       temp[i] = Items[i];
     temp[numItems++] = k;
     Items = temp;
     arraySize *= 2;
   }
}

void IntList::Print(std::ostream &output) const {
   for(int i = 0; i < numItems; i++)
     output << Items[i] << ", ";
   output << std::endl;
}

int IntList::Length () const {
  return numItems;
}

int main() {
  IntList *test;
  test = new IntList(100, 13);
  for(int i = 0; i < 10; i++) {
    test->AddToEnd(i);
  }
  test->Print(std::cout);
  std::cout << "num entries : " << test->Length() << std::endl;
  for(int i = 0; i < 10; i++) {
    test->AddToEnd(i + 10);
  }
  test->Print(std::cout);
  std::cout << "num entries : " << test->Length() << std::endl;
  std::cout << "Test DONE" << std::endl;
  return 0;
}
