#include<iostream>
#include<vector>
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
node*takeTreeInput()
{
    int data,childrenCount;
    cout<<"enter root data =";
    cin>>data;
    //if we give an empty tree as input
    if(data==-1)
        return NULL;
    node*root=new node(data);
    cout<<"enter number of childrens of "<<root->data<<"=";
    cin>>childrenCount;
    for(int i=0;i<childrenCount;i++)
    {
        node*child=takeTreeInput();
        root->v.push_back(child);
    }
    return root;
}
void printTreeDetailed(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    for(int i=0;i<root->v.size();i++)
    {
        cout<<root->v[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->v.size();i++)
    {
        printTreeDetailed(root->v[i]);
    }
}
int main()
{
    node*root=takeTreeInput();
    printTreeDetailed(root);

}
