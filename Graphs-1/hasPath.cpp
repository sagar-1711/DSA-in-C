#include<iostream>
using namespace std;
bool hasPathDFS(int**edges,int n,int v1,int v2,bool*visited)
{
    if(edges[v1][v2]==1)
        return true;
    visited[v1]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[v1][i]==1 && visited[i]==false)
        {
            if(hasPathDFS(edges,n,i,v2,visited))
                return true;
        }
    }
    return false;
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
    int v1,v2;
    cin>>v1>>v2;
    if(hasPathDFS(edges,n,v1,v2,visited))
        cout<<"true";
    else
        cout<<"false";
}
