#include <math.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc_dist(float angle) {
  float velocity = 200.0;
  float gravity = 32.2;
  float time_in_air = (2.0*velocity*sin(angle));
  float distance = round((velocity*cos(angle))*time_in_air);
  return distance;
}
void start () {
  std::cout <<
	  "PICK AN ANGLE TO FIRE THE CANNON!!! WE ARE UNDER SIEGE!!!" << 
	  std:: endl;
  srand(time(NULL));
}
int get_enemy_dist() {
  return rand() % 3900;
}
int hit_check(float angle, int enemy_dist) {
  int off = calc_dist(angle) - enemy_dist;
  if (abs(off) < 100) {
    return 0;
  } else if (off < 0) {
    return -1;
  } else {
    return 1;
  }
}
int main() {
  float angle;
  int enemies_rem = 10;
  int enemy_dist = get_enemy_dist();
  int off;
  start();
  do {
    std::cin >> angle;
    if((off = hit_check(angle, enemy_dist)) == 0) {
      enemies_rem--;
      enemy_dist = get_enemy_dist();
      std::cout << "NOICE HIT !!!" << std::endl;
    } else if (off < 0) {
      std::cout << "SHOOT FARTHER!!!" << std::endl;
    } else {
      std::cout << "SHOOT CLOSER" << std::endl;
    }
    std::cout << "SHOOT AGAIN !!!" << std::endl;  
  } while (angle > 0 && enemies_rem > 0);
  std::cout << "There are : " << enemies_rem << "Enemies Left" << std::endl;
  return 0;
}
