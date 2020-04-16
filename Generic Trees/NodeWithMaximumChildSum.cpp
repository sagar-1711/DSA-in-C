
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
void nodeWithMaximumChildSum(node*root,int &maxsum,node**ansnode)
{
    if(root==NULL)
        return;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;
        nodeWithMaximumChildSum(root->children[i],maxsum,ansnode);
    }
    if(sum>maxsum)
    {
        maxsum=sum;
        *ansnode=root;
    }
    return;
}
node*nodeWithMaximumChildSum(node*root)
{
    int maxsum=INT_MIN;
    node*ansnode;
    nodeWithMaximumChildSum(root,maxsum,&ansnode);
    return ansnode;
}
int main()
{
    node*root=takeInputLevelwise();
    node*ans=nodeWithMaximumChildSum(root);
    cout<<endl<<ans->data;

}
