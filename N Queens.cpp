//https://venus.cs.qc.edu/~waxman/211/nqueens.pdf
//Use Memory Allocation and Dynamic programming to optain 
#include <iostream>
#include<cmath>
using namespace std;

bool test(int Q[], int c){
  for(int i=0; i<c; i++)
  if(Q[i]==Q[c] || abs(Q[c]-Q[i]) == (c - i))
    return false;
  return true;
}
//NO BOARD
int NQueens(int n){
  int *Q = new int[n];//// Dynamically declare an array of size n and initialize the first element to 0.
  int c=0;
  Q[0]=0;
  int solutions=0;
   while (c >= 0) { 
      c++;
      if(c == n){
   			solutions++;
			c--; 
      }  
      else Q[c] = -1;
      while (c >= 0) {
         Q[c]++;
         if(Q[c]==n) c--;
      else if(test(Q,c))break;// get out of "Q[c]++" and restart C++ (Next Col)
    }
  }
  delete []Q;//Deletes the array
  return solutions;//Solutions for n
}
int main(){
  int n;
  cout<<"Please enter how many solutions you want to see ";
  cin>>n;
  for (int i=1; i<=n;i++){
    cout<<"There are "<< NQueens(i) <<" solutions to the "<<i<<" Queens problem"<<endl;
  }
  cout<<"Enjoy!";
  return 0;
}    