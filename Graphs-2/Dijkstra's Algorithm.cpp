#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int findMinVertexIndex(int*distance,bool*visited,int n)
{
    int minVertex=-1;
    //find vertex with min weight and which is not be visited
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(int**edges,int n)
{
    int*distance=new int[n];
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;

    }
    distance[0]=0;
    //out of all unvisited vertices pick the one with min weight
    for(int i=0;i<n;i++)
    {
        //we find minVertex.It is the vertex whose distance is minimum;
        int minVertex=findMinVertexIndex(distance,visited,n);
        visited[minVertex]=true;
        //Explore all unvisited neighbours of minvertex
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0 && !visited[j])
            {
                int dist=distance[minVertex]+edges[minVertex][j];
                if(dist<distance[j])
                {
                    distance[j]=dist;
                }
            }
        }
    }
    //print MST
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete[] visited;
    delete[] distance;

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
    for(int i=0;i<e;i++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    dijkstra(edges,n);
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}

