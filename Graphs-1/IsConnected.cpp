#include<iostream>
using namespace std;
void DFShelper(int**edges,int n,int sv,bool*visited)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && visited[i]==false)
        {
            DFShelper(edges,n,i,visited);
        }
    }
}
bool DFS(int**edges,int n,bool*visited)
{
	DFShelper(edges,n,0,visited);
	for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            return false;

    }
    return true;
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
    bool ans=DFS(edges,n,visited);
    if(ans)
        cout<<"true";
    else
        cout<<"false";
}
