#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "hill.h"
#include "stone.h"
#include "log.h"

using namespace std;

class Swamp{//Класс болото
ofstream gnuplot;//Файл вывода точек
public:
Swamp(){};
void Stoner(double x0, double y0, double z0, double R0);
void Loger(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
void Hiller(double x0, double y0, double z0, double sigmax0, double sigmay0);
void Swamper();
};