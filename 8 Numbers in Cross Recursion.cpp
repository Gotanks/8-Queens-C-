//Recursive 8 Cross
#include <iostream> 
#include <cmath> 
using namespace std; 
 
void print(int Q[8]){
    static int count=0;
cout << "Solution #"<<++count<< endl<<endl;
 
            cout<<" "<<Q[1]<<Q[2]<<endl;
            cout<<Q[0]<<Q[3]<<Q[4]<<Q[5]<<endl;
            cout<<" "<<Q[6]<<Q[7];
 
            cout<<endl<<endl;
}
 
bool pass(int Q[8], int c){
    int tb[8][5]={
        {-1},
        {0,-1},
        {1,-1},
        {0,1,2,-1},
        {1,2,3,-1},
        {2,4,-1},
        {0,3,4,-1},
        {3,4,5,6,-1}
    };
    for(int i=0; i<c; i++)
                if(Q[i]==Q[c])return false;
    for(int i=0; tb[c][i]!=-1; i++)
                if(abs(Q[c]-Q[tb[c][i]])==1)return false;
            return true;
}
void move(int q[], int i){
    if(i==8){ 
        print(q); 
        return; 
    } 
   for(int j=0;j<8;j++){ 
       q[i]=j; 
       if(pass(q,i))
           move(q,i+1);
   } 
}
 
int main() { 
 int q[8]; 
 move(q,0); 
}