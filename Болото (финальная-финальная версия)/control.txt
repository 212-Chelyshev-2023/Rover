#include "includes.h"

extern int q;//Просмотр вызова болота

Control::Control(){
  swamper=new Swamp();
  processoring=new Processor();
}

void Control::PrintFinish(ofstream &control_log_file, string &A){//Функция печати в control log файл (control log файл, строка из файла)
  time_t t1;//Время
  tm t;//Структура времени
  t1=time(NULL);
  t=*localtime(&t1);
  control_log_file << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << " Генерация: " << A << " завершена" << endl;
}

void Control::Program(string &A, int k, ofstream &control_log_file){
  double x, y, z, R, sigmax, sigmay, x1, y1, x2, y2;//Переменные для задания камней, холмов, бревен
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
      x=10;
      y=5;
      z=1.3;
      R=1;
      swamper->Stoner(x, y, z, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==3){
      x1=20;
      y1=25;
      x2=15;
      y2=17;
      R=1;
      swamper->Loger(x1, y1, x2, y2, R);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==4){
      x=11;
      y=10;
      z=5;
      sigmax=1.3;
      sigmay=1;
      swamper->Hiller(x, y, z, sigmax, sigmay);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==5){
      swamper->Swamper();
      PrintFinish(control_log_file, A);
    }
  }else{
    B=A.substr(pos+1);
    if (k==1){
      double sizex=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double sizey=atof(B.c_str());
      swamper=new Swamp(sizex, sizey);
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
      swamper->Stoner(x, y, z, R);
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
      swamper->Loger(x1, y1, x2, y2, R);
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
      swamper->Hiller(x, y, z, sigmax, sigmay);
      q=1;
      PrintFinish(control_log_file, A);
    }else if (k==6){
      double x0=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double y0=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double da0=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double db0=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double klir0=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double xf=atof(B.c_str());
      i=B.size();
      for (int j=0; j<i; j++){
        if (B[j]==' '){
          pos=j;
          break;
        }
      }
      B=B.substr(pos+1);
      double yf=atof(B.c_str());
     // string S=B;
     // cout << B << "\n";
      processoring=new Processor(x0, y0, da0, db0, klir0, xf, yf);
     // processoring->Print();
      if (processoring->Programm(*swamper)){
        PrintFinish(control_log_file, A);
      }else{
        control_log_file << "Не получилось построить маршрут для исходных координат точек A и B " << " Повторите попытку с новыми координатами\n";
      }
     // rovering->Definition_position();
     // rovering->Definition(*swamper);
     // rovering->Definition_angle();
     // rovering->Position();
     // rovering->Definition_direction(S);
     // rovering->Print();
     // rovering->Move(*swamper);
     // rovering->Print();
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
