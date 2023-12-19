#include "includes.h"

using namespace std;

class Stone{//Класс камень
double x, y, z, R;//Параметры для камней, R- радиус полусферы
public:
Stone(double x0, double y0, double z0, double R0);
double ConstructStone(double x0, double y0);//Функция построения камня в виде полусферы (координаты точки по икс, игрек)
};