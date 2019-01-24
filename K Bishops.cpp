//https://venus.cs.qc.edu/~waxman/211/k%20bishops%20on%20an%20nXn%20chessboard.pdf
#include <iostream>
#include<cmath>
using namespace std;
//TODO, find and know the difference between between the row and column
bool test(int Q[], int c, int n){
  for(int i=0; i<c; i++)
  if((Q[c]/n - Q[i]/n) == abs(Q[c]%n - Q[i]%n))//here
    return false;
  return true;
}
//Modified NQueens board
int kBishops(int n, int k){//Fix up the NQueens okay function
  int *q = new int[n];
  int *Q = new int[k];
  int c=0;
  q[0]=0;
  Q[0]=0;
  int solutions=0;
   while (c >= 0) { 
      c++;
      if(c == k){
   			solutions++;
			c--; 
      }  
      else Q[c] = Q[c-1];
      while (c >= 0) {
         Q[c]++;
         if(Q[c]==n*n) c--;//n by n board
      else if(test(Q,c,n))break;// get out of "Q[c]++" and restart C++ (Next Col)
    }
  }
  delete []Q;//Deletes the array
  return solutions;//Solutions for k
}
int main(){
  int n, k;
  cout<<"Please enter a number for n board (to exit please write any negative number i.e: '-1')"<<endl;
  cin>>n;
  if(n <= -1){
    cout<<"Exiting program!";
    exit(1);//or return 0;
  }
  cout<<"Please enter a number of bishops k"<<endl;
  cin>>k;
    cout<<"There are "<<kBishops(n, k) <<" solutions to the "<<n<<" Bishops problem"<<endl;
  return 0;
}    