//https://venus.cs.qc.edu/~waxman/211/stable%20marriage%20using%20backtrack%20assignment.pdf
#include <iostream>
using namespace std;

void print(int q[], int& count){
cout << "Solution #"<<++count<< endl;
            for(int i=0; i<3; i++)
                cout<<i<<"  "<<q[i]<<endl;          
}
 
bool ok(int q[], int col){//I've set up the possibilities like so to look more appealing
    int mp[3][3]=  {0,2,1,//Men
            0,2,1,
            1,2,0};
    int wp[3][3]=  {2,1,0,//Women
            0,1,2,
            2,0,1};
 
    for(int i=0; i<col; i++)
        if(q[col]==q[i])
            return false;
    for(int i = 0; i < col; i++) {
        if( mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col] )
            return false;
        if( mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i] )
            return false;
    }
    return true;
}
 
void backtrack(int &c){
    c--;
    if(c==-1){
        exit(1);
    }
}
 
int main(){
int q[3], c, count=0;
c=0;
q[0]=0;
while(true){ 
  c++;
    if(c==3){
      print(q, count);
      backtrack(c);
      }
         
    else q[c] =-1;
    while (true){
      q[c]++; 
            if(q[c]==3){ 
                backtrack(c);
            continue; 
            }
 
           if(ok(q,c))break;
      }
  }
}