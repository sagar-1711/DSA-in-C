#include<iostream>
#include<queue>
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
node*levelWiseInput()
{
    int data;
    cout<<"enter root node = ";
    cin>>data;
    node*root=new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node*ele=q.front();
        q.pop();
        cout<<"Enter left child of "<<ele->data<<"=";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            node*leftchild=new node(leftdata);
            ele->left=leftchild;
            q.push(leftchild);


        }
        cout<<"Enter right child of "<<ele->data<<"=";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            node*rightchild=new node(rightdata);
            ele->right=rightchild;
            q.push(rightchild);
        }
    }
    return root;
}
bool isBSTHelper(node*root,int minbound,int maxbound)
{
    if(root==NULL)
        return true;
    if(root->data<minbound || root->data>maxbound)
        return false;
    bool isleftBST=isBSTHelper(root->left,INT_MIN,root->data);
    bool isrightBST=isBSTHelper(root->right,root->data,INT_MAX);
    return isleftBST && isrightBST;
}
bool isBST(node*root)
{
    return isBSTHelper(root,INT_MIN,INT_MAX);

}
int main()
 {
     node*root=levelWiseInput();
     if(isBST(root))
        cout<<"true";
     else
        cout<<"false";

}
