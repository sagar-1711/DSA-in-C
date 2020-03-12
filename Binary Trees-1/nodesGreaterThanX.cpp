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
int countNodesGreaterThanX(node*root, int x)
{
    if(root==NULL)
        return 0;
    int count=0;    //int count=root->data>x?1:0;
    if(root->data>x)
        count=1;
    int leftcount=countNodesGreaterThanX(root->left,x);
    int rightcount=countNodesGreaterThanX(root->right,x);
    return count+leftcount+rightcount;

}


int main()
{   int x;
    cout<<"enter x";
    cin>>x;
    node*root=treeInput();
    printTreeDetailed(root);
    int nodesgreaterthanX=countNodesGreaterThanX(root,x);
    cout<<nodesgreaterthanX;
}
