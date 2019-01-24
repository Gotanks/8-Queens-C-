//Recursive 8 Cross
#include <iostream> 
#include <cmath> 
using namespace std; 
 
void print(int q[]){
  static int count = 0;
cout << "Solution # "<<++count<< endl;
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
void move(int q[], int i){
    if(i==3){ 
        print(q); 
        return; 
    } 
   for(int j=0;j<3;j++){ 
       q[i]=j; 
       if(ok(q,i))
           move(q,i+1);
   } 
}
 
int main() { 
 int q[3]; 
 move(q,0); 
}