
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
void replacewithlevel(node*root,int level)
{
    if(root==NULL)
        return;
    root->data=level;
    replacewithlevel(root->left,level+1);
    replacewithlevel(root->right,level+1);
}
void printInOrder(node*root)
{
    if(root==NULL)
        return;
    printInOrder(root->left);
    cout<<root->data<<endl;
    printInOrder(root->right);


}
void changeToDepthTree(node*root)
{
    replacewithlevel(root,0);
    printInOrder(root);

}
int main()
{
    node*root=treeInput();
    changeToDepthTree(root);

}
