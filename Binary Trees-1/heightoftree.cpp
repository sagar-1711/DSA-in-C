#include<iostream>
 #include<algorithm>
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
int height(node*root)
{
    if(root==NULL)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);

}


int main()
{
    node*root=treeInput();
    printTreeDetailed(root);
    int h=height(root);
    cout<<h;

}
