#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void pBlue(string str){
     cout<<"\033[1;34m"<<str<<"\033[0m";
}
void pRed(string str){
    cout<<"\033[1;31m"<<str<<"\033[0m";
}
void pGreen(string str){
    cout<<"\033[1;32m"<<str<<"\033[0m";
}
void pGreen(int i){
    cout<<"\033[1;32m"<<i<<"\033[0m";
}
void clear(){
    system("CLS");
}
void pTable(int a[9][9],bool b[9][9]){
clear();
pRed("\n+");
for(int j=0;j<9;j++){
    pRed("---+");
}
for(int i=0;i<9;i++){
    pRed("\n|");
    for(int j=0;j<9;j++){
        if(b[i][j]){
            cout<<" ";
            if(a[i][j]==0){
                cout<<" ";
            }
            else{
                pGreen(a[i][j]);
                
            }
            cout<<" ";

        }
        else{
            if(a[i][j]==0){
                cout<<"   ";
            }
            else{
                cout<<" "<<a[i][j]<<" ";
            }
            
        }
        
        if((j+1)%3==0){
            pRed("|");
        }
        else{
            cout<<"|";
        }
    }

    pRed("\n+");
    for(int j=0;j<9;j++){
        if((i+1)%3==0){
            pRed("---+");
        }
        else{
            pBlue("---");
        if((j+1)%3==0){
            pRed("+");
        }
        else{
            cout<<"+";
        }
        }
        
}

}
}
int ran(){
    return rand()%9 +1;
}
bool rules(int a[9][9], int x, int y, int v){
    for(int i=0;i<9;i++){
        //soton_moteghayer_va_satr_sabet
        if((i!=y) and (v==a[x][i])){
            return false;
        }
        //satr_moteghayer_va_soton_sabet
        if((i!=x) and (v==a[i][y])){
            return false;
        }
    }
    int ii=x-(x%3);
    int jj=y-(y%3);
    for(int i=ii;i<ii+3;i++){
    for(int j=jj;j<jj+3;j++){
        if(!(i==x and j==y)and (v==a[i][j])){
            return false;
        }
    }
}
return true;
}
void init(int a[9][9] , bool b[9][9]){
  for (int i=0 ; i<9 ; i++){
    for (int j=0 ; j<9 ; j++){
      a[i][j] = 0;
      b[i][j] = false;
    }
  }
}
void rSudoku(int a[9][9] , bool b[9][9], int d){
  
  init(a , b);
  int r, f , temp , eror;
  f=d;
  for (int i=0 ; i<9 ; i++){
    for (int j=0 ; j<9 ; j++){
      r = rand() % 10 + 1;
      eror = 0;
      if (r <=(d/10) ){
        do{
          temp = ran();
          eror++;
          if (eror == 20){
            rSudoku(a , b, d);
            return;
          }
        }while(!rules(a , i , j , temp));
        a[i][j] = temp;
        b[i][j] = true;
      }
      else{
         r = rand() % 10 + 1; 
      }
    }
  }
}
bool end(int a[9][9] , bool b[9][9]){
  for (int i=0 ; i<9 ; i++){
    for (int j=0 ; j<9 ; j++){
      if (a[i][j] == 0){
        return false;
      }
    }
  }

  for (int i=0 ; i<9 ; i++){
    for (int j=0 ; j<9 ; j++){
      if (!b[i][j]){
        if (!rules(a , i , j , a[i][j])){
          return false;
        }
      }
    }
  }

  return true;
}


int main(){
   srand(time(0));
  int a[9][9] , x , y , v, d;
  bool b[9][9];
  pGreen("\nHI LETS PLAY SUDOKU :\)");
  pRed("\nenter the DIFICULLTY:(DICULTY IS BY PERCENTAGE)");
  cin>>d;
  rSudoku(a , b, d);
  do{
        do{
            pTable(a , b);
            
            pGreen("\n\nplz first enter the location of ur value then set ur value:(x is row,y is column,v is value)");
            pRed("\nREMEMBER YOU CAN CHOOSE UR VALUE BETWEEN 1 TO 9 AND IF U ENTER 10 THREE TIMES U CAN EXIT THE GAME");
            pBlue("\nYOU CAN'T CHANGE THE NUMBERS THAT WERE ALREADY IN TABLE!! SOOOO becarefull to won't set ur location wrong");
            pGreen("\nGOOD LUCK!!");
            pRed("\n\n\t\t\t\t \' x \>\> y \>\> value \' : ");
            cin>>x>>y>>v;
        }while( !( (x==10 && y==10 && v==10) || ( (0<=x && x<=8)&&(0<=y && y<=8)&&(0<=v && v<=9) ) ));
        if (b[x][y]){
        continue;
        }
        if (x==10){
        system("color C");
        pRed("\n\n Exit...");
        
         return 0;
        }
        a[x][y] = v;
  }while(!end(a , b));

  pGreen("\n\n You win...");
  system("color A");
  return 0;
}