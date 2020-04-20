#include<iostream>
using namespace std;
void DFShelper(int**edges,int n,int sv,bool*visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && visited[i]==false)
        {
            DFShelper(edges,n,i,visited);
        }
    }
}
void DFS(int**edges,int n,bool*visited)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            DFShelper(edges,n,i,visited);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    int f,s;
    for(int i=0;i<e;i++)
    {
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    DFS(edges,n,visited);
}
