// file.cpp, Maggie Johnson
// Description: An illustration of file processing
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  char file_name[20];
  char buff[32];
  buff[31] = '\0';
  cout << endl << "Enter the name of the file: "; cin >> file_name;
  ifstream People(file_name, ios::in);
  while(People >> buff) cout << buff << endl;
  return 0;
} 
