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

class Hill{//Класс холм
double x, y, z, sigmax, sigmay, a;//Параметры для гор, sigmax-размытие по x, sigmay-по y, a-это недиагональный элемент нашей матрицы 
public:
Hill(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0);
double Gauss(double x0, double y0);//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
};