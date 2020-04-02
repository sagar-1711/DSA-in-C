#include<iostream>
using namespace std;
//root of N should be perfect square
bool isValid(int row,int col,int board[9][9],int value)
{
    //checking in row and column
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==value)
            return false;
        if(board[i][col]==value)
            return false;
    }
    //checking for box in which board[row][col] is present
    int rsi=row-row%3;
    int rei=rsi+3;
    int csi=col-col%3;
    int cei=csi+3;
    for(int i=rsi;i<rei;i++)
    {
        for(int j=csi;j<cei;j++)
        {
            if(board[i][j]==value)
                return false;
        }
    }
    return true;
}
void printBoard(int board[9][9])
{
    cout<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sudokoSolver(int row,int col,int board[9][9])
{
    if(row==9)
    {
        return true;
    }
    if(col==9)
    {
        return sudokoSolver(row+1,0,board);
    }
    if(board[row][col]!=0)
    {
        return sudokoSolver(row,col+1,board);
    }
    for(int value=1;value<=9;value++)
    {
        if(isValid(row,col,board,value))
        {
            board[row][col]=value;
            if(sudokoSolver(row,col+1,board)==true)
                return true;
        }
        board[row][col]=0;
    }
    //kept all the numbers but none is valid so sudoku is unsolvable
    return false;
}
int main()
{
    int board[9][9];
    cout<<"Enter board values";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
    if(sudokoSolver(0,0,board)==true)
        printBoard(board);
    else
        cout<<"Sudoku cannot be solved";

}
