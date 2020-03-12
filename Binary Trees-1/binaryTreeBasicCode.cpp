#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node*left;
        node*right;
        node(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

void printTreeDetailed(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
        cout<<"L"<<root->left->data<<",";
    if(root->right!=NULL)
        cout<<"R"<<root->right->data<<" ";
    cout<<endl;
    printTreeDetailed(root->left);
    printTreeDetailed(root->right);

}
int main()
{
    node*btn1=new node(1);
    node*btn2=new node(2);
    node*btn3=new node(3);
    node*btn4=new node(4);
    node*btn5=new node(5);
    btn1->left=btn2;
    btn1->right=btn3;
    btn2->left=btn4;
    btn2->right=btn5;
    printTreeDetailed(btn1);

}
