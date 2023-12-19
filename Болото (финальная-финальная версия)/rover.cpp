#include "includes.h"
#define EPS 0.00001

Rover::Rover(double x0, double y0, double da0, double db0, double klir0, double xf0, double yf0){
  x=x0;
  y=y0;
  da=da0;
  db=db0;
  klir=klir0;
  xf=xf0;
  yf=yf0;
}

void Rover::Definition(Swamp &swamp){
  points_move_file.open("points_move_file.txt");
  Points_rover.resize(3);
  for (int i=0; i<3; i++){
    Points_rover[i].resize(3);
  }
  Points_rover[1][1]=swamp.Points[posx][posy];
  Points_rover[1][2]=swamp.Points[posx+1][posy];
  Points_rover[1][0]=swamp.Points[posx-1][posy];
  Points_rover[0][0]=swamp.Points[posx-1][posy+1];
  Points_rover[0][1]=swamp.Points[posx][posy+1];
  Points_rover[0][2]=swamp.Points[posx+1][posy+1];
  Points_rover[2][0]=swamp.Points[posx-1][posy-1];
  Points_rover[2][1]=swamp.Points[posx][posy-1];
  Points_rover[2][2]=swamp.Points[posx+1][posy-1];
  points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
}

void Rover::Definition_position(){
  double x0=0, y0=0;
  int i=0, j=0;
  if ((fabs(x-x0))<EPS){
    i=0;
    if ((fabs(y-y0))<EPS){
      j=0;
    }else{
      do{
        y0+=0.3;
        j+=1;
      }while ((fabs(y-y0))>=EPS);
    }
  }else{
    do{
      x0+=0.3;
      i+=1;
    }while (((fabs(x-x0))>=EPS));
    if ((fabs(y-y0))<EPS){
      j=0;
    }else{
      do{
        y0+=0.3;
        j+=1;
      }while ((fabs(y-y0))>=EPS);
    }
  }
  posx=i;
  posy=j;
  Y=posy*0.3;
  X=posx*0.3;
 // cout << X << " " << Y <<  " " << posx << " " << posy << endl;
}

void Rover::Definition_angle(){
  double a1=atan(Points_rover[0][1]/0.6);
  double b1=atan(Points_rover[1][2]/0.6);
  double a2, b2;
  a2=atan(Points_rover[2][1]/0.6);
  b2=atan(Points_rover[1][0]/0.6);
  a=max(a1, a2);
  b=max(b1, b2);
}

bool Rover::Position(){
  if (a>da){
  //  cout << "a= " << a << ' ' << "da= " << da << endl;
    return false;
  }else if (b>db){
  //  cout << "b= " << b << ' ' << "db= " << db << endl;
    return false;
  }else{
    return true;
  }
}

bool Rover::Move(Swamp &swamp){
  if (dir==1){
      if (!Klirens(swamp)){
        //cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j][posy+(1-i)+1];
      }
    }
    posy+=1;
    Y+=0.3;
    Definition_angle();
    if (!Position()){
     // cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j][posy+(1-i)-1];
        }
      }
      posy-=1;
      Y-=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==2){
      if (!Klirens(swamp)){
     //   cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)+1];
      }
    }
    posx+=1;
    posy+=1;
    X+=0.3;
    Y+=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)-1];
        }
      }
      posx-=1;
      posy-=1;
      X-=0.3;
      Y-=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==3){
      if (!Klirens(swamp)){
     //   cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)];
      }
    }
    posx+=1;
    X+=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)];
        }
      }
      posx-=1;
      X-=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==4){
      if (!Klirens(swamp)){
      //  cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)-1];
      }
    }
    posx+=1;
    posy-=1;
    X+=0.3;
    Y-=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)+1];
        }
      }
      posx-=1;
      posy+=1;
      X-=0.3;
      Y+=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==5){
      if (!Klirens(swamp)){
       // cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j][posy+(1-i)-1];
      }
    }
    posy-=1;
    Y-=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j][posy+(1-i)+1];
        }
      }
      posy+=1;
      Y+=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==6){
      if (!Klirens(swamp)){
     //   cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)-1];
      }
    }
    posx-=1;
    posy-=1;
    X-=0.3;
    Y-=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)+1];
        }
      }
      posx+=1;
      posy+=1;
      X+=0.3;
      Y+=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else if (dir==7){
      if (!Klirens(swamp)){
     //   cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)];
      }
    }
    posx-=1;
    X-=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)];
        }
      }
      posx+=1;
      X+=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }else{
      if (!Klirens(swamp)){
      //  cout << "Клиренс, ровер падает dir= " << dir << endl;
        return false;
      }
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        Points_rover[i][j]=swamp.Points[posx-1+j-1][posy+(1-i)+1];
      }
    }
    posx-=1;
    posy+=1;
    X-=0.3;
    Y+=0.3;
    Definition_angle();
    if (!Position()){
    //  cout << "Движение невозможно dir= " << dir << endl;
      for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
          Points_rover[i][j]=swamp.Points[posx-1+j+1][posy+(1-i)-1];
        }
      }
      posx+=1;
      posy-=1;
      X+=0.3;
      Y-=0.3;
      return false;
    }
    points_move_file << X << " " << Y << " " << Points_rover[1][1] << endl;
  }
  return true;
}

void Rover::Definition_direction(int dir0){
//  int i;
//  string A="NN";
//  string B="NE";
//  string C="EE";
//  string D="SE";
//  string E="SS";
//  string F="SW";
//  string G="WW";
//  string H="NW";
//  if (O0[0]=='N'){
//    if (O0[1]=='N'){
//      i=1;
//    }else if (O0[1]=='E'){
//      i=2;
//    }else{
//      i=8;
//    }
//  }else if (O0[0]=='E'){
//    i=3;
//  }else if (O0[0]=='S'){
//    if (O0[1]=='S'){
//      i=5;
//    }else if (O0[1]=='E'){
//      i=4;
//    }else{
//     i=6;
//    }
//  }else if (O0[0]=='W'){
//    i=7;
//  } 
  dir=dir0;
}

bool Rover::Klirens(Swamp &swamp){
  int k=0;
  if (dir==1){
    if ((swamp.Points[posx-1][posy+2]-Points_rover[0][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx][posy+2]-Points_rover[0][1])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+1][posy+2]-Points_rover[0][2])<klir){
      k+=1;
    }
   // cout << "Клиренс\n";
   // cout << swamp.Points[posx-1][posy+2] << " " << Points_rover[0][0] << " " << swamp.Points[posx][posy+2] << " " << Points_rover[0][1] << " " << swamp.Points[posx+1][posy+2] << " " << Points_rover[0][2] << " " << swamp.Points[posx-1][posy+2]-Points_rover[0][0] << " " << swamp.Points[posx][posy+2]-Points_rover[0][1] << " " << klir << " " << k  << " " << "Клиренс закончен\n";
  }else if (dir==2){
    if ((swamp.Points[posx+1][posy+2]-Points_rover[0][1])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+2][posy+2]-Points_rover[0][2])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+2][posy+1]-Points_rover[1][2])<klir){
      k+=1;
    }
  }else if (dir==3){
    if ((swamp.Points[posx+2][posy+1]-Points_rover[0][2])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+2][posy]-Points_rover[1][2])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+2][posy-1]-Points_rover[2][2])<klir){
      k+=1;
    }
  }else if (dir==4){
    if ((swamp.Points[posx+2][posy-1]-Points_rover[1][2])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+2][posy-2]-Points_rover[2][2])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+1][posy-2]-Points_rover[2][1])<klir){
      k+=1;
    }
  }else if (dir==5){
    if ((swamp.Points[posx-1][posy-2]-Points_rover[2][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx][posy-2]-Points_rover[2][1])<klir){
      k+=1;
    }
    if ((swamp.Points[posx+1][posy-2]-Points_rover[2][2])<klir){
      k+=1;
    }
  }else if (dir==6){
    if ((swamp.Points[posx-2][posy-1]-Points_rover[1][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-2][posy-2]-Points_rover[2][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-1][posy-2]-Points_rover[2][1])<klir){
      k+=1;
    }
  }else if (dir==7){
    if ((swamp.Points[posx-2][posy+1]-Points_rover[0][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-2][posy]-Points_rover[1][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-2][posy-1]-Points_rover[2][0])<klir){
      k+=1;
    }
  }else{
    if ((swamp.Points[posx-2][posy+2]-Points_rover[0][0])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-1][posy+2]-Points_rover[0][1])<klir){
      k+=1;
    }
    if ((swamp.Points[posx-2][posy+1]-Points_rover[1][0])<klir){
      k+=1;
    }
  }
  if (k==3){
    return true;
  }else {
    return false;
  }
}

bool Rover::Proverka(){
  int k=0;
  if ((fabs(xf-X))<EPS){
    k+=1;
  }
  if ((fabs(yf-Y))<EPS){
    k+=1;
  }
  if (k==2){
    return true;
  }else{
    return false;
  }
}

void Rover::Print(){
  cout << x << " " << y << " " << da << " " << db << " " << klir << endl;
//  for (int i=0; i<3; i++){
//    for (int j=0; j<3; j++){
//      cout << Points_rover[i][j] << ' ';
//    }
//    cout << endl;
//  }
//  cout <<' ' << a << ' ' << b << ' ';
//  cout << endl;
//  cout << dir << "\n";
}
