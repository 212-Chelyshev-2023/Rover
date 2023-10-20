#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include "boundary.h"

//212 группа
//Челышев Сергей Дмитриевич
//Болото с boundary и control

using namespace std;

double sizex, sizey;//Переменные для размеров болота
vector<double>Points;//Точки болота
int q=0;//Просмотр вызова болота
vector<Hill>Hills;//Вектор холмов
vector<Stone>Stones;//Вектор камней
vector<Log>Logs;//Вектор бревен

int main(void){
  Boundary();//Класс boundary
  return 0;
}