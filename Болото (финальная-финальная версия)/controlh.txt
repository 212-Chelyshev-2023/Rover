#include "includes.h"

using namespace std;


class Control{//Класс Control
Swamp *swamper;
Processor *processoring;
int sizex0, sizey0;
public:
Control();
void Program(string &A, int k, ofstream &control_log_file);
void Print(ofstream &control_log_file, int k, string &A);//Функция печати в control log файл (control log файл, что за команда, строка из файла)
void PrintFinish(ofstream &control_log_file, string &A);//Функция печати в control log файл (control log файл, строка из файла)
};