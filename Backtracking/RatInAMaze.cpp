#include<iostream>
using namespace std;
void print(int solution[20][20],int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }


}
void printPath(int x,int y,int maze[20][20],int solution[20][20],int n)
{
    if(x==n-1 && y==n-1)
    {
        solution[x][y]=1;
        print(solution,n);
        return;
    }
    if(x<0 || y<0 ||x>=n ||y>=n ||solution[x][y]==1 || maze[x][y]==0)
    {
        return;
    }
    solution[x][y]=1;
    printPath(x+1,y,maze,solution,n);
    printPath(x,y+1,maze,solution,n);
    printPath(x-1,y,maze,solution,n);
    printPath(x,y-1,maze,solution,n);
    solution[x][y]=0;
    return;
}
int main()
{
    //size of maze will be n*n
    int n,i,j;
    cin>>n;
    int maze[20][20];
    cout<<"Enter the maze"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    int solution[20][20];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            solution[i][j]=0;
        }
    }
    printPath(0,0,maze,solution,n);
}
