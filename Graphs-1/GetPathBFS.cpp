#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> getpathBFS(int**edges,int n,int sv,int ev,bool*visited)
{
    queue<int> q;
    unordered_map<int,int> parent;
    q.push(sv);
    visited[sv]=true;
    bool done=false;
    while(!q.empty() && done==false)
    {
        int front=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[front][i]!=0 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
                parent[i]=front;
                if(i==ev)
                {
                    done=true;
                    break;
                }

            }
        }
    }
    vector<int> v;
    if(done==false)
    {
        v.push_back(-1);
        return v;
    }

    while(ev!=sv)
    {
        v.push_back(ev);
        ev=parent[ev];
    }
    v.push_back(sv);
    return v;




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
    vector<int> output;
    output=getpathBFS(edges,n,v1,v2,visited);
    if(output.front()==-1)
        exit(0);
	for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }

}
