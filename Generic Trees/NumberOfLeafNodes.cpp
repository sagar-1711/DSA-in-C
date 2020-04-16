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
node*takeInputLechildrenelwise()
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
int numLeafnodes(node*root)
{
    if(root->children.size()==0)
        return 1;
    int c=0;
    for(int i=0;i<root->children.size();i++)
    {
        c+=numLeafnodes(root->children[i]);
    }
    return c;
}
int main()
{

    node*root=takeInputLechildrenelwise();
    cout<<"Total number of leaf nodes are "<<numLeafnodes(root);

}
