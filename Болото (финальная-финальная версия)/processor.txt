#include "includes.h"
#define EPS 0.00001

Processor::Processor(double x0, double y0, double da0, double db0, double klir0, double xf0, double yf0){
  x=x0;
  y=y0;
  da=da0;
  db=db0;
  klir=klir0;
  xf=xf0;
  yf=yf0;
  rovering=new Rover(x, y, da, db, klir, xf, yf);
}

void Processor::Print(){
  cout << x << " " << y << " " << da << " " << db << " " << klir << endl;
  rovering->Print();
}

bool Processor::Programm(Swamp &swamp){
  int k=0;
  int n=0;
  int i=1;
  bool t=false;
  bool m=false;
  double rx, ry;
  int dir=0;
  rovering->Definition_position();
  rovering->Definition(swamp);
  rovering->Definition_angle();
  if (!(rovering->Position())){
    cout << "Ровер упал в начальной точке\n";
    return false;
  }
  rx=xf-x;
  ry=yf-y;
 // cout << rx << ' ' << ry << endl;
  while (fabs(rx)>EPS || fabs (ry)>EPS){
   // cout << x << ' ' << y << endl;
      if (rx>0){
          if (ry>0){
              dir=2;
          }else if (fabs(ry-0)<EPS){
                 dir=3;
             }else{
                 dir=4;
             }
         }else if (fabs(rx-0)<EPS){
             if (ry>0){
                 dir=1;
             }else if (fabs(ry-0)<EPS){
                 return true;
                 break;
             }else{
                 dir=5;
             }
         }else{
             if (ry>0){
                 dir=8;
             }else if (fabs(ry-0)<EPS){
                 dir=7;
             }else{
                 dir=6;
             }
         }
         rovering->Definition_direction(dir);
         if (rovering->Move(swamp)){
             if (dir==1){
                y+=0.3;
             }else if (dir==2){
                 x+=0.3;
                 y+=0.3;
             }else if (dir==3){
                 x+=0.3;
             }else if (dir==4){
                 x+=0.3;
                 y-=0.3;
             }else if (dir==5){
                 y-=0.3;
             }else if (dir==6){
                 x-=0.3;
                 y-=0.3;
             }else if (dir==7){
                 x-=0.3;
             }else{
                 x-=0.3;
                 y+=0.3;
             }
         }else{
             rovering->Definition_direction(1);
             t=rovering->Move(swamp);
             if (t){
               y+=0.3;
             }
             while (t==false){
               rovering->Definition_direction(8);
               m=rovering->Move(swamp);
               while (m){
                   x-=0.3;
                   y+=0.3;
                 rovering->Definition_direction(1);
                 t=rovering->Move(swamp);
                 if (t){
                   y+=0.3;
                   break;
                 }
                 rovering->Definition_direction(8);
                 m=rovering->Move(swamp);
               }
               if (t){
                 break;
               }
               rovering->Definition_direction(2);
                m=rovering->Move(swamp);
               while (m){
                    x+=0.3;
                    y+=0.3;
                  rovering->Definition_direction(1);
                  t=rovering->Move(swamp);
                  if (t){
                    y+=0.3;
                    break;
                  }
                  rovering->Definition_direction(2);
                  m=rovering->Move(swamp);
                }
                if (t){
                  break;
                }
               rovering->Definition_direction(3);
                 m=rovering->Move(swamp);
                while (m){
                     x+=0.3;
                   rovering->Definition_direction(1);
                   t=rovering->Move(swamp);
                   if (t){
                     y+=0.3;
                     break;
                   }
                   rovering->Definition_direction(3);
                   m=rovering->Move(swamp);
                 }
                 if (t){
                   break;
                 }
               rovering->Definition_direction(7);
                 m=rovering->Move(swamp);
                while (m){
                     x-=0.3;
                   rovering->Definition_direction(1);
                   t=rovering->Move(swamp);
                   if (t){
                     y+=0.3;
                     break;
                   }
                   rovering->Definition_direction(7);
                   m=rovering->Move(swamp);
                 }
                 if (t){
                   break;
                 }
               rovering->Definition_direction(4);
                m=rovering->Move(swamp);
               while (m){
                    x+=0.3;
                 y-=0.3;
                  rovering->Definition_direction(1);
                  t=rovering->Move(swamp);
                  if (t){
                    y+=0.3;
                    break;
                  }
                  rovering->Definition_direction(4);
                  m=rovering->Move(swamp);
                }
                if (t){
                  break;
                }
               rovering->Definition_direction(6);
                m=rovering->Move(swamp);
               while (m){
                    x-=0.3;
                 y-=0.3;
                  rovering->Definition_direction(1);
                  t=rovering->Move(swamp);
                  if (t){
                    y+=0.3;
                    break;
                  }
                  rovering->Definition_direction(6);
                  m=rovering->Move(swamp);
                }
                if (t){
                  break;
                }
               rovering->Definition_direction(5);
                m=rovering->Move(swamp);
               while (m){
                    y-=0.3;
                  rovering->Definition_direction(1);
                  t=rovering->Move(swamp);
                  if (t){
                    y+=0.3;
                    break;
                  }
                  rovering->Definition_direction(5);
                  m=rovering->Move(swamp);
                }
                if (t){
                  break;
                }
             }
           
         }
    rx=xf-x;
    ry=yf-y;
   }
  //cout << x << ' ' << y;
  return true;
  /*while (rovering->Position()){
    dir=1;
    rovering->Definition_direction(dir);
    if (!(rovering->Move(swamp))){
      dir=2;
      rovering->Definition_direction(dir);
      if (!(rovering->Move(swamp))){
        dir=3;
        rovering->Definition_direction(dir);
        if (!(rovering->Move(swamp))){
          dir=4;
          rovering->Definition_direction(dir);
          if (!(rovering->Move(swamp))){
            dir=5;
            rovering->Definition_direction(dir);
            if (!(rovering->Move(swamp))){
              dir=6;
              rovering->Definition_direction(dir);
              if (!(rovering->Move(swamp))){
                dir=7;
                rovering->Definition_direction(dir);
                if (!(rovering->Move(swamp))){
                  dir=8;
                  rovering->Definition_direction(dir);
                  if (!(rovering->Move(swamp))){
                    cout << "Ровер не смог доехать до конца\n";
                    return false;
                  }else{
                    if (rovering->Proverka()){
                      return true;
                    }
                  }
                }else{
                  if (rovering->Proverka()){
                    return true;
                  }
                }
              }else{
                if (rovering->Proverka()){
                  return true;
                }
              }
            }else{
              if (rovering->Proverka()){
                return true;
              }
            }
          }else{
            if (rovering->Proverka()){
              return true;
            }
          }
        }else{
          if (rovering->Proverka()){
            return true;
          }
        }
      }else{
        if (rovering->Proverka()){
          return true;
        }
      }
    }else{
      if (rovering->Proverka()){
        return true;
      }
    }
  }
  return false;
*/
}
