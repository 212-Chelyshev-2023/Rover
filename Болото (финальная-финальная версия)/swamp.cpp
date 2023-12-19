#include "includes.h"

extern int q;//Просмотр вызова болота

Swamp::Swamp(double sizex0, double sizey0){
  sizex=sizex0;
  sizey=sizey0;
}

void Swamp::Swamper(){
  int m=0, k=0;//Позиция
  gnuplot.open("Gnuplot.txt");
  for (double i=0.0; i<=sizex; i+=0.3){
    for (double j=0.0; j<=sizey; j+=0.3){
      gnuplot << i << " " << j << " " << Points[m][k] << "\n";
      k+=1;
    }
    gnuplot << "\n";
    k=0;
    m+=1;
  }
}

void Swamp::Hiller(double x0, double y0, double z0, double sigmax0, double sigmay0){
  double Z;//Высота
  int m=0, k=0;//Позиция
  Hills.push_back(Hill(x0, y0, z0, sigmax0, sigmay0));
  int n=Hills.size();
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      vector<double>v;
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Hills[g].Gauss(i, j);
        }
        v.push_back(Z);
      }
      Points.push_back(v);
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Hills[g].Gauss(i, j);
        }
        Points[m][k]+=Z;
        k+=1;
      }
      k=0;
      m+=1;
    }
  }
}

void Swamp::Loger(double x1_0, double y1_0, double x2_0, double y2_0, double R0){
  double Z;//Высота
  int m=0, k=0;//Позиция
  Logs.push_back(Log(x1_0, y1_0, x2_0, y2_0, R0));
  int n=Logs.size();
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      vector<double>v;
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Logs[g].ConstructLog(i, j);
        }
      v.push_back(Z);
      }
      Points.push_back(v);
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Logs[g].ConstructLog(i, j);
        }
      Points[m][k]+=Z;
        k+=1;
      }
      k=0;
      m+=1;
    }
  }
}

void Swamp::Stoner(double x0, double y0, double z0, double R0){
  double Z;//Высота
  int m=0, k=0;//Позиция
  Stones.push_back(Stone(x0, y0, z0, R0));
  int n=Stones.size();
  if (q==0){
    for (double i=0.0; i<=sizex; i+=0.3){
      vector<double>v;
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Stones[g].ConstructStone(i, j);
        }
      v.push_back(Z);
      }
      Points.push_back(v);
    }
  }else{
    for (double i=0.0; i<=sizex; i+=0.3){
      for (double j=0.0; j<=sizey; j+=0.3){
        Z=0;
        for (int g=0; g<n; g++){
          Z+=Stones[g].ConstructStone(i, j);
        }
      Points[m][k]+=Z;
        k+=1;
      }
      k=0;
      m+=1;
    }
  }
}