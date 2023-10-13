#include "control.h"

extern double sizex, sizey;//Переменные для размеров болота
extern int q;//Просмотр вызова болота

void Control::PrintFinish(ofstream &control_log_file, string &A){//Функция печати в control log файл (control log файл, строка из файла)
  time_t t1;//Время
  tm t;//Структура времени
  t1=time(NULL);
  t=*localtime(&t1);
  control_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Генерация: " << A << " завершена" << endl;
}

void Control::Program(string &A, int k, ofstream &control_log_file){
  double x, y, z, R, sigmax, sigmay, a, x1, y1, x2, y2;//Переменные для задания камней, холмов, бревен
  int i, n=0, pos;//Переменные для цикла, определения заданных переменных, позиции
  string B;//Строка для изменения
  Print(control_log_file, k, A);
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
      swamper.Stoner(x, y, z, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==3){
      x1=1;
      y1=1;
      x2=1;
      y2=1;
      R=1;
      swamper.Loger(x1, y1, x2, y2, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==4){
      x=1;
      y=1;
      z=1;
      sigmax=1;
      sigmay=1;
      a=1;
      swamper.Hiller(x, y, z, sigmax, sigmay, a);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==5){
      swamper.Swamper();
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
      swamper.Stoner(x, y, z, R);
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
      swamper.Loger(x1, y1, x2, y2, R);
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
      swamper.Hiller(x, y, z, sigmax, sigmay, a);
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
