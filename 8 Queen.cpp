#include <iostream>
#include<cmath>//needed for absolute values
using namespace std;


void print(int Q[], int& count){
  //This function takes in a column, and outputs whether or not there is a Queen in that particular one or not
  cout << "Solution #"<<++count<< endl;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(Q[i]==j)
      cout <<"X";
      else
      cout<<"-";
    }
    cout<<endl;
  }
  cout<<endl;
}

bool test(int Q[], int c){
  for(int i=0; i<c; i++)
  if(Q[i]==Q[c] || abs(Q[c]-Q[i]) == (c - i))
    return false;
    //we've talked about absolute value in lab before, and it'll help to make sure that c is not a negative
  return true;
}

void backtrack(int &c){//Void could be achieved too; however, I chose to go with int since I was more comfortable knowing what exactly I am returning, rather than having no return type with a forced close (exit(1)
  //If the conditions of the function is not met, the array and column will go back and retry until there is a matching patern. IF not, the program will terminate (going out of bounds)
  c--;
  if(c==-1){
    exit(1);
  }
}

int main(){
  int Q[8], i, c, count=0;
  c=0;
  Q[0]=0;
  while (true){//This conditional checks to see if all spots on a grid have been checked.
    c++;
    if(c==8){
      print(Q, count);
      backtrack(c);//Function to go to the previous column
    }
    else Q[c] =-1;
    while (true){
      Q[c]++; 
      if(Q[c]==8){
        backtrack(c);
        if (c == 1) return 0;
        continue; 
        //Continue is used as an alternative to goto to let the loop of any kind continue under a specific condition, this one goes to the next row
      }
      if(test(Q,c))break;// get out of "Q[c]++" and restart C++ (Next Col)
    }
  }
}
