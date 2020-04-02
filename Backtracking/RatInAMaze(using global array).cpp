#include<iostream>
using namespace std;
int maze[100][100];
int solution[100][100];
void print(int n)
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
void printPath(int x,int y,int n)
{
    if(x==n-1 && y==n-1)
    {
        solution[x][y]=1;
        print(n);
        return;
    }
    if(x<0 || y<0 ||x>=n ||y>=n ||solution[x][y]==1 || maze[x][y]==0)
    {
        return;
    }
    solution[x][y]=1;
    printPath(x+1,y,n);
    printPath(x,y+1,n);
    printPath(x-1,y,n);
    printPath(x,y-1,n);
    solution[x][y]=0;
    return;
}
int main()
{
    //size of maze will be n*n
    int n,i,j;
    cin>>n;
    cout<<"Enter the maze"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    printPath(0,0,n);
}
