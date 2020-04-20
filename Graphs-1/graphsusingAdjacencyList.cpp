#include<iostream>
#include<vector>
using namespace std;
class Graph
{
public:
    int V;
    //array vector
    vector<int>*adjList;
    Graph(int v)
    {
        V=v;
        adjList=new vector<int>[V];

    }
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto x:adjList[i])
            {
                cout<<x<<",";
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
    g.printAdjList();

}
