#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class node
{
public:
    int data;
    vector<node*> children;
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
        for(int i=0;i<currnode->children.size();i++)
        {
            node*child=currnode->children[i];
            if(i==currnode->children.size()-1)
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
            currnode->children.push_back(child);
            q.push(child);
        }
    }
}
node*nextLarger(node*root,int n,node*nextlarge)
{
    if(root==NULL)
        return NULL;
    if(root->data>n && root->data<nextlarge->data)
    {
        nextlarge=root;
    }
    for(int i=0;i<root->children.size();i++)
    {
        nextlarge=nextLarger(root->children[i],n,nextlarge);

    }
    return nextlarge;

}
node*nextLarger(node*root,int n)
{
    node*nextlarge;
    nextlarge->data=INT_MAX;
    return nextLarger(root,n,nextlarge);
}
int main()
{
    int n;
    node*root=takeInputLevelwise();
    cout<<"Enter n";
    cin>>n;
    node*ans=nextLarger(root,n);
    cout<<ans->data;

}
