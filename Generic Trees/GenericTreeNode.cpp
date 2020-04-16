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
void preorder(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<endl;
    for(int i=0;i<root->v.size();i++)
    {
        preorder(root->v[i]);
    }
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
    node*n1=new node(5);
    node*n2=new node(2);
    node*n3=new node(9);
    node*n4=new node(8);
    node*n5=new node(7);
    node*n6=new node(15);
    node*n7=new node(1);
    n1->v.push_back(n2);
    n1->v.push_back(n3);
    n1->v.push_back(n4);
    n1->v.push_back(n5);
    n3->v.push_back(n6);
    n3->v.push_back(n7);
    preorder(n1);
    cout<<endl;
    printTreeDetailed(n1);

}
