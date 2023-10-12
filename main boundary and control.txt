#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>

//212 группа
//Челышев Сергей Дмитриевич
//Болото с boundary и control

using namespace std;

double sizex, sizey;//Переменные для размеров болота
vector<double>Points;//Точки болота
int q=0;//Просмотр вызова болота

class Boundary{//Класс Boundary
ifstream config_file;//Конфигурационный файл
ifstream comand_file;//Командный файл
ofstream boundary_log_file;//Boundary log файл
ofstream control_log_file;//Control log файл
public:
Boundary();
void PrintStart(ofstream &boundary_log_file);//Функция печати в boundary log файл (boundary log файл)
int What_is(string A);//Функция определения поступившей команды (строка из файла)
void Print(ofstream &boundary_log_file, int k, string A);//Функция печати в boundary log файл (boundary log файл, что за комнада, строка файла)
void PrintFinish(ofstream &boundary_log_file, string A);//Функция печати в boundary log файл (boundary log файл, строка файла)
};

class Control{//Класс Control
public:
Control(string &A, int k, ofstream &control_log_file);
void Print(ofstream &control_log_file, int k, string &A);//Функция печати в control log файл (control log файл, что за команда, строка из файла)
void PrintFinish(ofstream &control_log_file, string &A);//Функция печати в control log файл (control log файл, строка из файла)
};

class Stone{//Класс камень
double x, y, z, R;//Параметры для камней, R- радиус полусферы
public:
Stone(double x0, double y0, double z0, double R0);
double ConstructStone(double x0, double y0);//Функция построения камня в виде полусферы (координаты точки по икс, игрек)
};

class Log{//Класс бревно
double x1, x2, y1, y2, R;//Параметры для бревен, координаты для двух точек бревна, R- радиус бревна
public:
Log(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
double ConstructLog(double x0, double y0);//Функция построения бревна (в виде колбасы) (координаты точки по икс, игрек)
};

class Hill{//Класс холм
double x, y, z, sigmax, sigmay, a;//Параметры для гор, sigmax-размытие по x, sigmay-по y, a-это недиагональный элемент нашей матрицы 
public:
Hill(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0);
double Gauss(double x0, double y0);//Функция Гаусса для холмов и ямок (координата точки по икс, по игрек)
};

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

class Swamp{//Класс болото
ofstream gnuplot;//Файл вывода точек
vector<Hill>Hills;//Вектор холмов
vector<Stone>Stones;//Вектор камней
vector<Log>Logs;//Вектор бревен
public:
Swamp(double x0, double y0, double z0, double R0);
Swamp(double x1_0, double y1_0, double x2_0, double y2_0, double R0);
Swamp(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0);
Swamp();
};

Swamp::Swamp(){
  int m=0;//Позиция
  gnuplot.open("Gnuplot.txt");
  for (double i=0.0; i<=sizex; i+=0.3){
    for (double j=0.0; j<=sizey; j+=0.3){
      gnuplot << i << " " << j << " " << Points[m] << "\n";
      m+=1;
    }
    gnuplot << "\n";
  }
}

Swamp::Swamp(double x0, double y0, double z0, double sigmax0, double sigmay0, double a0){
  double Z;//Высота
  int m=0;//Позиция
  Hills.push_back(Hill(x0, y0, z0, sigmax0, sigmay0, a0));
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Hills[0].Gauss(i, j);
        Points.push_back(Z);
      }
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Hills[0].Gauss(i, j);
        Points[m]+=Z;
        m+=1;
      }
    }
  }
}

Swamp::Swamp(double x1_0, double y1_0, double x2_0, double y2_0, double R0){
  double Z;//Высота
  int m=0;//Позиция
  Logs.push_back(Log(x1_0, y1_0, x2_0, y2_0, R0));
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Logs[0].ConstructLog(i, j);
        Points.push_back(Z);
      }
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Logs[0].ConstructLog(i, j);
        Points[m]+=Z;
        m+=1;
      }
    }
  }
}

Swamp::Swamp(double x0, double y0, double z0, double R0){
  double Z;//Высота
  int m=0;//Позиция
  Stones.push_back(Stone(x0, y0, z0, R0));
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Stones[0].ConstructStone(i, j);
        Points.push_back(Z);
      }
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        Z+=Stones[0].ConstructStone(i, j);
        Points[m]+=Z;
        m+=1;
      }
    }
  }
}

void Control::PrintFinish(ofstream &control_log_file, string &A){//Функция печати в control log файл (control log файл, строка из файла)
  time_t t1;//Время
  tm t;//Структура времени
  t1=time(NULL);
  t=*localtime(&t1);
  control_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Генерация: " << A << " завершена" << endl;
}

Control::Control(string &A, int k, ofstream &control_log_file){
  double x, y, z, R, sigmax, sigmay, a, x1, y1, x2, y2;//Переменные для задания камней, холмов, бревен
  int i, n=0, pos;//Переменные для цикла, определения заданных переменных, позиции
  string B;//Строка для изменения
  Print(control_log_file, k, A);
  std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
  i=A.size();
  for (int j=0; j<i; j++){
    if (A[j]==' '){
      n+=1;
      if (n==2){
        pos=j;
        break;
      }
    }
  }
  if (n==1){
    if (k==2){
      x=1;
      y=1;
      z=1;
      R=1;
      Swamp(x, y, z, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==3){
      x1=1;
      y1=1;
      x2=1;
      y2=1;
      R=1;
      Swamp(x1, y1, x2, y2, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==4){
      x=1;
      y=1;
      z=1;
      sigmax=1;
      sigmay=1;
      a=1;
      Swamp(x, y, z, sigmax, sigmay, a);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==5){
      Swamp();
      PrintFinish(control_log_file, A);
    }
  }else{
    B=A.substr(pos+1);
    if (k==1){
      sizex=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      sizey=atof(B.c_str());
      PrintFinish(control_log_file, A);
    }else if (k==2){
      x=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      y=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      z=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      R=atof(B.c_str());
      Swamp(x, y, z, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==3){
      x1=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      y1=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      x2=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      y2=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      R=atof(B.c_str());
      Swamp(x1, y1, x2, y2, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==4){
      x=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      y=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      z=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      sigmax=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      sigmay=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      a=atof(B.c_str());
      Swamp(x, y, z, sigmax, sigmay, a);
      q=1;
      PrintFinish(control_log_file, A);
    }
  }
}

void Control::Print(ofstream &control_log_file, int k, string &A){//Функция печати в control log файл (control log файл, что за команда, строка из файла)
  time_t t1;//Время
  tm t;//Структура времени
  if (k==-2){
    t1=time(NULL);
    t=*localtime(&t1);
    control_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Получена неверная команда, обратитесь в командный файл" << endl;
  }else{
    t1=time(NULL);
    t=*localtime(&t1);
    control_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Приступаю к выполнению команды: " << A << endl;
  }
}

Boundary::Boundary(){
  int k;//Что за команда
  string A;//Строка из файла
  config_file.open("config_file.txt");
  getline(config_file, A);
  comand_file.open(A);
  if (!comand_file){
    cout << "Командный файл не найден\n";
  }
  config_file.close();
  boundary_log_file.open("boundary_log_file.txt");
  PrintStart(boundary_log_file);
  control_log_file.open("control_log_file.txt");
  PrintStart(control_log_file);
  while (!comand_file.eof()){
    getline(comand_file, A);
    k=What_is(A);
    Print(boundary_log_file, k, A);
    Control (A, k, control_log_file);
    PrintFinish(boundary_log_file, A);
  }
  control_log_file.close();
  boundary_log_file.close();
  comand_file.close();
}

void Boundary::PrintFinish(ofstream &boundary_log_file, string A){//Функция печати в boundary log файл (boundary log файл, строка файла)
  time_t t1;//Время
  tm t;//Структура времени
  t1=time(NULL);
  t=*localtime(&t1);
  boundary_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Команда: " << A << " успешно завершена" << endl;
}

void Boundary::Print(ofstream &boundary_log_file, int k, string A){//Функция печати в boundary log файл (boundary log файл, что за комнада, строка файла)
  time_t t1;//Время
  tm t;//Структура времени
  if (k==-2){
    t1=time(NULL);
    t=*localtime(&t1);
    boundary_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Получена неверная команда, обратитесь в командный файл" << endl << endl;
  }else{
    t1=time(NULL);
    t=*localtime(&t1);
    boundary_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Получена команда: " << A << endl;
  }
}

int Boundary::What_is(string A){//Функция определения поступившей команды (строка из файла)
  string F;//Строка для изменения
  int k;//Что за команда
  string B="marsh";
  string C="stone";
  string D="log";
  string E="hill";
  string G="file";
  int i;//Счетчик
  int pos;//Позиция
  i=A.size();
  for (int j=0; j<i; j++){
    if (A[j]==' '){
      pos=j;
      break;
    }
  }
  F=A.substr(pos+1);
  if (F[0]==B[0]){
    k=1;
  }else if (F[0]==C[0]){
    k=2;
  }else if(F[0]==D[0]){
    k=3;
  }else if (F[0]==E[0]){
    k=4;
  }else if (F[0]==G[0]){
    k=5;
  }else{
    k=-2;
  }
  return k;
}

void Boundary::PrintStart(ofstream &boundary_log_file){//Функция печати в boundary log файл (boundary log файл)
  time_t now;//Время
  char* dt;//Дата
  now=time(0);
  dt=ctime(&now);
  boundary_log_file << "The local date and time is: " << dt << endl;
}

int main(void){
  Boundary();//Класс boundary
  return 0;
}