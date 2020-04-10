
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
node*treeInput()
{   int data;
    cin>>data;
    if(data==-1)
        return NULL;
    node*root=new node(data);
    root->left=treeInput();
    root->right=treeInput();
    return root;

}
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
node*removeLeafNodes(node*root)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
        return NULL;
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;

}


int main()
{

    node*root=treeInput();
    printTreeDetailed(root);
    root=removeLeafNodes(root);
    printTreeDetailed(root);


}
