#include <iostream>
#include<cmath>
using namespace std;
 
void print(int Q[], int& count){
    cout<<endl;
    cout << "      Solution # "<<++count<< endl;
    int i,j,k,l;
    typedef char box[5][7];
    box bb,wb,*board[8][8],wq,bq;
//fill in bb=blackbox, wb=whitebox, wq=whitequeen and bw=blackqueen
       for(i=0;i<5;i++)
               for( j=0;j<7;j++){
                   wb[i][j]=' ';
                   bb[i][j]=char(219);
 
            if((i>0 && i<4) && (j==3 || (i-j==1) || (i-j==2) || (i+j==7) || (i+j==8)))
                bq[i][j]=char(219);
            else bq[i][j]=' ';  
     
            if((i>0 && i<4) && (j==3 || (i-j==1) || (i-j==2) || (i+j==7) || (i+j==8)))
                wq[i][j]=' ';           
            else wq[i][j]=char(219);
        }
//fill board with pointers to bb and wb in alternate positions
       for(i=0;i<8;i++)
               for(j=0;j<8;j++){
                       if((i+j)%2==0){ 
                           board[i][j]=&wb;
                        if(Q[i]==j) board[i][j]=&bq;
                       }
                       else {
                           board[i][j]=&bb;
                           if(Q[i]==j) board[i][j]=&wq;
                       }
               }
// print the board via the pointers in array board
// first print upper border
               cout<<"      ";
               for(i=0;i<7*8;i++) cout<<'_';
               cout<<endl;
// now print the board
               for(i=0;i<8;i++)
                   for(k=0;k<5;k++){
                       cout<<"     "<<char(179); //print left border
                       for(j=0;j<8;j++)
                           for(l=0;l<7;l++)
                               cout<<(*board[i][j])[k][l];
                       cout<<char(179)<<endl; // at end of line print bar and then newline
                   }
//before exiting print lower border
                   cout<<"      ";
                   for(i=0;i<7*8;i++)
                       cout<<char(196);
                   cout<<endl;
}
 
bool test(int Q[], int c){
    for(int i=0; i<c; i++)
               if(Q[i]==Q[c] || abs(Q[c]-Q[i]) == (c - i))return false;
    return true;
}
 
void backtrack(int &c){
    c--;
    if(c==-1){
        exit(1);
    }
}
 
int main(){
int Q[8], i, c, count=0;
 
c=0;
Q[0]=0;
while(true){
  c++; 
         
            if(c==8){
                print(Q, count);
                backtrack(c);
            }
         
    else Q[c] =-1;
    while(true){
      Q[c]++;
 
            if(Q[c]==8){ 
                backtrack(c);
            continue; 
            }
 
           if(test(Q,c))break;
    }
}
}//main