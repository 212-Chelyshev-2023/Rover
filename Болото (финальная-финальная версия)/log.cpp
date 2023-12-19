#include "includes.h"

Log::Log(double x1_0, double y1_0, double x2_0, double y2_0, double R0){
  x1=x1_0;
  x2=x2_0;
  y1=y1_0;
  y2=y2_0;
  R=R0;
}

double Log::ConstructLog(double x0, double y0){//Функция построения бревна (в виде колбасы) (коордщинаты точки по икс, игрек)
  double k=y2-y1;
  double b=x1-x2;
  double c=k*k+b*b;
  double var1=(-y1*b-x1*k);
  double var2=b*(x1+x2)/2-k*(y1+y2)/ 2;
  double d1=abs(k*x0+b*y0+var1)/sqrt(c);
  double d2=abs(-b*x0+k*y0+var2)/sqrt(c);
  if (R*R>d1*d1 && c/4>d2*d2) {
    return sqrt(R*R-d1*d1);
  }
  return 0;
}