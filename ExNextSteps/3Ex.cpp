#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void accf (int& speed, int inc) {
  speed += inc;
  inc = -1;
}

int main () {
  int speed = 0;
  int acc = 0;
  std::cout << "please enter current speed, then inc amount" << std::endl;
  std::cin >> speed;
  std::cin >> acc;
  accf(speed, acc);
  std::cout << "we now have speed : " << speed << " and acc : " << acc << std::endl;
 return 0; 
}
