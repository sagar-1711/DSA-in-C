#include<iostream>
#include<algorithm>
using namespace std;
class Edge
{
public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight; //we can interpret it as if weight of first element< weight of second element then it is fine otherwise need to rearrange it
}
int findParent(int v,int*parent)
{
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}
void kruskals(Edge*input,int n,int e)
{
    //sort the input array in ascending order according to weight using inbuilt sort function
    sort(input,input+e,compare);
    //create output array of size n-1
    Edge*output=new Edge[n-1];
    //create parent array of type intto store parent of each  vertex.there are n vertices so size of parent array will be n
    int*parent=new int[n];
    //initially each vertex is parent of itself is parent[i]=i
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;//i is used to iterate over sorted Edge array
    while(count<n-1)
    {
        Edge currEdge=input[i];
        //check if we can add the currEdge in MST or not
        int sourceparent=findParent(currEdge.source,parent);
        int destparent=findParent(currEdge.dest,parent);
        if(sourceparent!=destparent)
        {
            output[count]=currEdge;
            parent[sourceparent]=destparent;
            count++;
        }
        i++;
    }
    //print MST print edge with less value first
    for(int i=0;i<n-1;i++)
    {
        if(output[i].source<output[i].dest)
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
}
int main()
{
    //n=number of vertices,e=no of edges of graph
    int n,e;
    cin>>n>>e;
    //creating input array of type edge and size e;
    Edge*input=new Edge[e];
    //take input of graph into input array
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,e);


}
