#include "includes.h"

using namespace std;

class Rover{
ofstream points_move_file;
double klir;
int dir=0;
int posx, posy;
double X, Y;
double x, y, da, db, xf, yf;
double a;
double b;
vector<vector<double>>Points_rover;
public:
Rover(double x0, double y0, double da0, double db0, double klir0, double xf0, double yf0);
void Definition(Swamp &swamp);
void Definition_position();
void Definition_angle();
bool Move(Swamp &swamp);
void Definition_direction(int dir0);
bool Position();
bool Klirens(Swamp &swamp);
bool Proverka();
void Print();
};
