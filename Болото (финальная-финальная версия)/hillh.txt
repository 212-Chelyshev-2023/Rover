#include "includes.h"

using namespace std;

class Hill{//Класс холм
double x, y, z, sigmax, sigmay, sigmaxy;//Параметры для гор, sigmax-размытие по x, sigmay-по y, a-это недиагональный элемент нашей матрицы 
public:
Hill(double x0, double y0, double z0, double sigmax0, double sigmay0);
double Gauss(double x0, double y0);//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
};