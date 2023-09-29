#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <math.h>
#include <vector>
#include "c.h"
#define HILL_HIGHT 13
#define STONE_HIGHT 3
#define LOG_HIGHT 3
#define SIGMA 15

//Болото с камнями и бревнами
//Челышев Сергей Дмитриеивч
//212 группа

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

double random(double a, double b){//Функция задания рандомных точек(два вещественных числа (диапозоны рандома))
  return a+((double)rand()/RAND_MAX)*(b-a);
}

Swamp::Swamp(double x, double y, int k1, int k2, int k3){
  double x0, y0, z0, sigmax0, sigmay0, R0, a0, x1_0, y1_0, x2_0, y2_0;//Переменные для заполнения векторов холмов, камней и бревен
  sizex=x;
  sizey=y;
  counthill=k1;
  countstone=k2;
  countlog=k3;
  for (int i=0; i<counthill; i++){
    x0=random(sizex/10, sizex*9/10);
    y0=random(sizey/10, sizey*9/10);
    z0=random(-HILL_HIGHT/2, HILL_HIGHT);
    sigmax0=random(SIGMA/5, SIGMA);
    sigmay0=random(SIGMA/5, SIGMA);
    a0=random(0, 2*3.1415);
    Hills.push_back(Hill(x0, y0, z0, sigmax0, sigmay0, a0));
  }
  for (int i=0; i<countstone; i++){
    x0=random(sizex/10, sizex*9/10);
    y0=random(sizey/10, sizey*9/10);
    z0=random(-HILL_HIGHT/2, HILL_HIGHT);
    R0=random(0, STONE_HIGHT);
    Stones.push_back(Stone(x0, y0, R0));
  }
  for (size_t i=0; i<countlog; i++){
    x1_0=random(sizex/10, sizex*9/10);
    x2_0=random(sizex/10, sizex*9/10);
    y1_0=random(sizey/10, sizey*9/10);
    y2_0=random(sizey/10, sizey*9/10);
    R0=random(0, LOG_HIGHT);
    Logs.push_back(Log(x1_0, y1_0, x2_0, y2_0, R0));
  }
}

void Swamp::Print(std::ofstream &file){//Функция печати болота в файл (файл)
  double z;//Высота для холмиков, камней, бревен
  for (double i=0.0; i<=sizex; i+=0.3){
    for (double j=0.0; j<=sizey; j+=0.3){
      z=0;
      for (int g=0; g<counthill; g++){
        z+=Hills[g].Gauss(i, j);
      }
      for (int g=0; g<countstone; g++){
        z+=Stones[g].ConstructStone(i, j);
      }
      for (int g=0; g<countlog; g++){
        z+=Logs[g].ConstructLog(i, j);
      }
      file <<i<<" "<<j<<" "<<z<<"\n";
    }
    file <<"\n";
  }
}

Stone::Stone(double x0, double y0, double R0){
  x=x0;
  y=y0;
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