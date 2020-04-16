#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class node
{
public:
    int data;
    vector<node*> v;
    node(int data)
    {
        this->data=data;
    }
};
void printTreeLevelWise(node*root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node*currnode=q.front();
        q.pop();
        cout<<currnode->data<<":";
        for(int i=0;i<currnode->v.size();i++)
        {
            node*child=currnode->v[i];
            if(i==currnode->v.size()-1)
                cout<<child->data;
            else
                cout<<child->data<<",";
            q.push(child);
        }
        cout<<endl;
    }
}
node*takeInputLevelwise()
{
    int rootData;
    cout<<"Enter root Data ";
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    queue<node*> q;
    node*root=new node(rootData);
    q.push(root);
    while(!q.empty())
    {
        node*currnode=q.front();
        q.pop();
        cout<<"Enter no of childrens of "<<currnode->data<<" ";
        int num;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            int childData;
            cout<<"enter next child for "<<currnode->data<<" ";
            cin>>childData;
            node*child=new node(childData);
            currnode->v.push_back(child);
            q.push(child);
        }
    }
}
bool containsX(node*root,int x)
{
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    for(int i=0;i<root->v.size();i++)
    {
        if(containsX(root->v[i],x))
            return true;
    }
    return false;
}
int main()
{
    int x;
    node*root=takeInputLevelwise();
    cout<<"enter x";
    cin>>x;
    cout<<endl;
    if(containsX(root,x))
        cout<<"true";
    else
        cout<<"false";
}
