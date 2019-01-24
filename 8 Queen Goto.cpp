#include<iostream>
using namespace std;
int main(){
    int board[8][8]={0}, r, c;//Making the chess board, and the row and column variables
    int counter=0;//a counter
    board[0][0]=1;//To use for the loops to check for compatable spots for the queens

    c=0;
NC: c++;//node for goto for column
    if(c==8) goto Print;

    r=-1;
NR: r++; //node for goto for row
    if(r==8) goto Backtrack;

    //row test
    for(int i=0; i<c; i++)//Index goes to c for checking queens
        if(board[r][i]==1) goto NR;//if Row(x) at Index(i) has a queen


    //up diagnoal test
    for(int i= 1; (r-i)>=0 && (c-i)>=0; i++)//If the specific row & specific column are >= than 0
        if(board[r-i][c-i]==1) goto NR;//if Row(x) at Index(i) has a queen


    //down diagnoal test
    for(int i=1; (r+i)<8 && (c-i)>=0; i++)//If statements to make sure the index does not go out of bounds
        if(board[r+i][c-i]==1) goto NR;//if Row(x) at Index(i) has a queen

    board[r][c]=1;
    goto NC;

Backtrack: c--; //backtracking
    if(c==-1){
    exit(1);
    return 0;
    }

    r=0;
    while(board[r][c]!=1){
    r++;
    }
    board[r][c]=0;
    goto NR;


Print: counter ++;
    cout<<"This is test number: "<<counter<<endl;
    for(r=0; r<8; r++){
        for(c=0; c<8; c++){
        if(board[r][c]==1) cout<<"X";
        else cout<<"-";
        }cout<<endl;
       }cout<<endl;

      goto Backtrack;
       return 0;

}