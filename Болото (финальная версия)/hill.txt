#include "hill.h"

Hill::Hill(double x0, double y0, double z0, double sigmax0, double sigmay0){
  srand(time(NULL));
  x=x0;
  y=y0;
  z=z0;
  sigmax=sigmax0;
  sigmay=sigmay0;
  sigmaxy=double(rand()%10000)/20000*sigmax*sigmay;
}

double Hill::Gauss(double x0, double y0){//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
  double e;//Экспонента из формулы Гаусса
  double r=sigmaxy/(sigmax*sigmay);
  e=exp(((x-x0)*(x-x0)/(sigmax*sigmax)+(y-y0)*(y-y0)/(sigmay*sigmay)-2*r*(x-x0)*(y-y0)/(sigmax*sigmay))/(2*r*r-2));
  return z*e;
}