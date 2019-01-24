//https://venus.cs.qc.edu/~waxman/211/eight%20numbers%20in%20a%20cross%20problem.pdf
#include <iostream>
#include<cmath>
using namespace std;

void print(int Q[8], int& count){
cout << "Solution #"<<++count<< endl;
            for(int i=0; i<8; i++){
                  for(int k=0; k<2; k++){
                if((i%2==0)&&(i!=4)&&(k==0)||(k==2))
                  cout<<endl;
                else if (i==0||i==6)
                  cout<<" ";
                  }
            cout<<Q[i];
            }
          cout<<endl;
}

bool pass(int Q[8], int tb[8][5], int c){
    for(int i=0; i<c; i++)
                if(Q[i]==Q[c])return false;
    for(int i=0; tb[c][i]!=-1; i++)
                if(abs(Q[c]-Q[tb[c][i]])==1)return false;
            return true;
}

int main(){
    int i, c, count=0;

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

int Q[8];
Q[0]=1;
c=0;
while(true){ c++;

            if(c==8){
                print(Q, count);
                c--;
            }

    else Q[c] =0;

    while(1){ Q[c]++;

            if(Q[c]>8){ c--;

                        if(c==-1){
                            return 0;
                        }
            continue;
            }

           if(pass(Q, tb, c))break;
      }
  }

}
