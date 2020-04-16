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
void LevelOrderTraversal(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty())
    {
        node*curr=q.front();
        q.pop();
        if(curr!=NULL)
        {
            cout<<curr->data<<" ";
            for(int i=0;i<curr->children.size();i++)
            {
                q.push(curr->children[i]);
            }
        }
        else
        {
            q.push(NULL);
            cout<<endl;
        }
        if(q.size()==1 && q.front()==NULL)
            break;
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
void replaceWithDepthhelper(node*root,int depth)
{
    if(root==NULL)
        return;
    root->data=depth;
    for(int i=0;i<root->children.size();i++)
    {
        replaceWithDepthhelper(root->children[i],depth+1);
    }
}
void replaceWithDepth(node*root)
{
    return replaceWithDepthhelper(root,0);
}
int main()
{
    node*root=takeInputLevelwise();
    replaceWithDepth(root);
    LevelOrderTraversal(root);

}
