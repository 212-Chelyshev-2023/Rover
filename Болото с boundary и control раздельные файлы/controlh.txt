#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "swamp.h"

using namespace std;


class Control{//Класс Control
Swamp swamper;
public:
Control(){};
void Program(string &A, int k, ofstream &control_log_file);
void Print(ofstream &control_log_file, int k, string &A);//Функция печати в control log файл (control log файл, что за команда, строка из файла)
void PrintFinish(ofstream &control_log_file, string &A);//Функция печати в control log файл (control log файл, строка из файла)
};