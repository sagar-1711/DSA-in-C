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
node*takeInputLevelWise()
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
bool isIdentical(node*root1,node*root2)
{
    if(root1==NULL || root2==NULL)
        return true;
    if(root1->data!=root2->data || root1->children.size()!=root2->children.size())
        return false;
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        return false;

    for(int i=0;i<root1->children.size();i++)
    {
        node*child1=root1->children[i];
        node*child2=root2->children[i];
        if(!isIdentical(child1,child2))
            return false;
    }
    return true;
}
int main()
{
    node* root1 = takeInputLevelWise();
    node* root2 = takeInputLevelWise();
    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

}
