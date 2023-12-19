#include "includes.h"

Boundary::Boundary(){
  controller=new Control();
  string G="end";
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
    if (A==G){
      break;
    }
    k=What_is(A);
 //   cout << k << "\n";
    Print(boundary_log_file, k, A);
    controller->Program(A, k, control_log_file);
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
  string H="rover";
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
  }else if (F[0]==H[0]){
    k=6;
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

