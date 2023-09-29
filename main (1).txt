#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <math.h>
#include <vector>
#include "c.h"
#define HILL_HIGHT 13
#define STONE_HIGHT 3
#define LOG_HIGHT 3
#define SIGMA 15

//Болото с камнями и бревнами
//Челышев Сергей Дмитриеивч
//212 группа

int main(void){
  srand(time(NULL));
  Swamp G(50, 50, 30, 30, 30);//Наше Болото (размер по икс, по игрек, число холмиков(ямок), число камней, число бревен)
  std::ofstream file("1.txt");//Файл для вывода Болота
  G.Print(file);
  return 0;
}