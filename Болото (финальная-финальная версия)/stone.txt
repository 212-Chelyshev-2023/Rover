#include "includes.h"

Stone::Stone(double x0, double y0, double z0, double R0){
  x=x0;
  y=y0;
  z=z0;
  R=R0;
}

double Stone::ConstructStone(double x0, double y0){//Функция построения камня в виде полусферы (координаты точки по икс, игрек)
  double z0;//Высота
  z0=(R)*(R)-(x-x0)*(x-x0)-(y-y0)*(y-y0);
  if (z0>=0){
    return sqrt(z0)+z;
  }
  else{
    return 0;
  }
}