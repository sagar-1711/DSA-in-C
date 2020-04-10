//we calculate height and isBalanced at same time.This reduce our time as we do not have to go down to each leaf node to calculate height of node.we simply return height for each node as we come back from NULL
//Time Complexity=O(n)
#include<algorithm>
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

bool isBalanced2(node*root,int*h)
{
    int lh=0,rh=0;
    if(root==NULL)
    {
        *h=0;
        return true;
    }

    bool isLeftBalanced=isBalanced2(root->left,&lh);
    bool isRightBalanced=isBalanced2(root->right,&rh);

    *h=1+max(lh,rh);
    if(lh-rh>1 || rh-lh>1)
        return false;
    if(isLeftBalanced && isRightBalanced)
        return true;
    else
        return false;
}


int main()
{
    int height=0;
    node*root=treeInput();
    printTreeDetailed(root);
    if(isBalanced2(root,&height))
        cout<<"true";
    else
        cout<<"false";
    cout<<endl;
    cout<<"height of tree"<<endl<<height;

}




