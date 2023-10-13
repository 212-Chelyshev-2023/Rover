#include "log.h"

Log::Log(double x1_0, double y1_0, double x2_0, double y2_0, double R0){
  x1=x1_0;
  x2=x2_0;
  y1=y1_0;
  y2=y2_0;
  R=R0;
}

double Log::ConstructLog(double x0, double y0){//Функция построения бревна (в виде колбасы) (коордщинаты точки по икс, игрек)
  double z0;//Высота
  z0=(R)*(R)-(y0-(x0-x1)*(y2-y1)/(x2-x1)-y1)*(y0-(x0-x1)*(y2-y1)/(x2-x1)-y1);
  if (z0>=0 && fabs(y0-((x1-x2)*x0/(y2-y1))-(y1+y2)/2+(x1-x2)*(x1+x2)/(2*(y2-y1)))<=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/2){
    return sqrt(z0);
  }else{
    return 0;
  }
}