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

class Log{//Класс бревно
double x1, x2, y1, y2, R;//Параметры для бревен, координаты для двух точек бревна, R- радиус бревна
public:
Log(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
double ConstructLog(double x0, double y0);//Функция построения бревна (в виде колбасы) (координаты точки по икс, игрек)
};