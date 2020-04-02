#include<iostream>
using namespace std;
bool isSafe(int row,int col,int n,int board[20][20])
{
    //checking for left upward diagonal
    int i,j;
    for(i=row-1,j=col;i>=0;i--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    //checking upwards in same column j remains same only i changes
    for(i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    //checking for right upward diagonal
    for(i=row-1,j=col+1;i>=0 and j<n;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    //if we reach here then it means it is safe place to put queen therefore return true
    return true;



}
void printPathHelper(int row,int n,int board[20][20])
{

    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col,n,board))
        {
            board[row][col]=1;
            printPathHelper(row+1,n,board);
            board[row][col]=0;
        }
    }
    return;
}

void placeNQueens(int n)
{
    int board[20][20];
     for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=0;
            }
        }
    printPathHelper(0,n,board);
}

int main()
{

  int n;
  cin >> n ;
  placeNQueens(n);


}
