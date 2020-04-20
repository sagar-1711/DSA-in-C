#include<iostream>
#include<vector>
using namespace std;
class Graph
{
public:
    int V;
    //array vector
    int**adjMatrix;
    Graph(int v)
    {
        V=v;
        adjMatrix=new int*[V];
        for(int i=0;i<V;i++)
        {
            adjMatrix[i]=new int[V];
            for(int j=0;j<V;j++)
            {
                adjMatrix[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v)
    {
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }
    void printadjMatrix()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<V;j++)
            {
                if(adjMatrix[i][j]==1)
                    cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.printadjMatrix();

}
