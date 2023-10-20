#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

class Stone{//Класс камень
double x, y, z, R;//Параметры для камней, R- радиус полусферы
public:
Stone(double x0, double y0, double z0, double R0);
double ConstructStone(double x0, double y0);//Функция построения камня в виде полусферы (координаты точки по икс, игрек)
};