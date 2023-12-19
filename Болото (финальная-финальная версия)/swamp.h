#include "includes.h"

using namespace std;

class Swamp{//Класс болото
double sizex, sizey;//Переменные для размеров болота
vector<Hill>Hills;//Вектор холмов
vector<Stone>Stones;//Вектор камней
vector<Log>Logs;//Вектор бревен
vector<vector<double>>Points;//Точки болота
ofstream gnuplot;//Файл вывода точек
public:
friend class Rover;
Swamp(){};
Swamp(double sizex0, double sizey0);
void Stoner(double x0, double y0, double z0, double R0);
void Loger(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
void Hiller(double x0, double y0, double z0, double sigmax0, double sigmay0);
void Swamper();
};