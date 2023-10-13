#include "hill.h"

Hill::Hill(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0){
  x=x0;
  y=y0;
  z=z0;
  sigmax=sigmax0;
  sigmay=sigmay0;
  a=a0;
}

double Hill::Gauss(double x0, double y0){//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
  double e;//Экспонента из формулы Гаусса
  e=exp((-1)*((cos(a)*(x-x0)+sin(a)*(y-y0))*(cos(a)*(x-x0)+sin(a)*(y-y0))/(sigmax)+(-sin(a)*(x-x0)+cos(a)*(y-y0))*(-sin(a)*(x-x0)+cos(a)*(y-y0))/sigmay));
  return z*e;
}