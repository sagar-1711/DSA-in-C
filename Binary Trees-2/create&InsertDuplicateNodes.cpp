//O(n^2)
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

void insertDuplicateNode(node*root)
{
    if(root==NULL)
        return;
    node*temp;
    node*duplicate=new node(root->data);
    temp=root->left;
    root->left=duplicate;
    duplicate->left=temp;
    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);

}
int main()
{
    node*root=treeInput();
    printTreeDetailed(root);
    insertDuplicateNode(root);
    printTreeDetailed(root);
}
