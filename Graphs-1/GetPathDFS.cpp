#include<iostream>
#include<vector>
using namespace std;
vector<int>*getpathDFS(int**edges,int n,int v1,int v2,bool*visited)
{
    if(v1==v2)
    {
        vector<int>*v=new vector<int>();
        v->push_back(v2);
        return v;
    }
    visited[v1]=true;
    vector<int>*output=new vector<int>();
    for(int i=0;i<n;i++)
    {
        if(edges[v1][i]==1 && visited[i]==0)
        {
            output=getpathDFS(edges,n,i,v2,visited);
            if(output!=NULL)
            {
                output->push_back(v1);
            	return output;
            }
        }

    }
    return NULL;

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
    vector<int>*output=new vector<int>();
    output=getpathDFS(edges,n,v1,v2,visited);
    if(output!=NULL)
    {
		for(int i=0;i<output->size();i++)
  		{
        	cout<<output->at(i)<<" ";
    	}
    }

}
