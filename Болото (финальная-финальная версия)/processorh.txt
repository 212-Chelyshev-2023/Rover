#include "includes.h"

using namespace std;

class Processor{
Rover *rovering;
double x, y, da, db, xf, yf;
double klir;
public:
Processor(){};
Processor(double x0, double y0, double da0, double db0, double klir0, double xf0, double yf0);
void Print();
bool Programm(Swamp &swamp);
};
