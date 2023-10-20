#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "control.h"

using namespace std;

class Boundary{//Класс Boundary
ifstream config_file;//Конфигурационный файл
ifstream comand_file;//Командный файл
ofstream boundary_log_file;//Boundary log файл
ofstream control_log_file;//Control log файл
Control controller;
public:
Boundary();
void PrintStart(ofstream &boundary_log_file);//Функция печати в boundary log файл (boundary log файл)
int What_is(string A);//Функция определения поступившей команды (строка из файла)
void Print(ofstream &boundary_log_file, int k, string A);//Функция печати в boundary log файл (boundary log файл, что за комнада, строка файла)
void PrintFinish(ofstream &boundary_log_file, string A);//Функция печати в boundary log файл (boundary log файл, строка файла)
};