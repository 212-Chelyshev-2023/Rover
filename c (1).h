#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <math.h>
#include <vector>
#define HILL_HIGHT 13
#define STONE_HIGHT 3
#define LOG_HIGHT 3
#define SIGMA 15

//Болото с камнями и бревнами
//Челышев Сергей Дмитриеивч
//212 группа

class Hill{//Класс гора
double x, y, z, sigmax, sigmay, a;//Параметры для гор, sigmax-размытие по x, sigmay-по y, a-это недиагональный элемент нашей матрицы 
public:
Hill(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0);
double Gauss(double x0, double y0);//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
};

class Stone{//Класс камень
double x, y, z, R;//Параметры для камней, R- радиус полусферы 
public:
Stone(double x0, double y0, double R0);
double ConstructStone(double x0, double y0);//Функция построения камня в виде полусферы (координаты точки по икс, игрек)
};

class Log{//Класс бревно
double x1, x2, y1, y2, R;//Параметры для бревен, координаты для двух точек бревна, R- радиус бревна
public:
Log(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
double ConstructLog(double x0, double y0);//Функция построения бревна (в виде колбасы) (коордщинаты точки по икс, игрек)
};

class Swamp{//Класс Болото
double sizex, sizey;//размеры сетки
int counthill, countstone, countlog;//Количество гор, камней, бревен
std::vector<Hill>Hills;//Вектор гор
std::vector<Stone>Stones;//Вектор камней
std::vector<Log>Logs;//Вектор бревен
public:
Swamp(double x, double y, int k1, int k2, int k3);
void Print(std::ofstream &file);//Функция вывода точек в файл (файл)
};

double random(double a, double b);////Функция задания рандомных точек(два вещественных числа (диапозоны рандома))