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
int minTree(node*root)
{
    if(root==NULL)
        return INT_MAX;
    int leftmin=minTree(root->left);
    int rightmin=minTree(root->right);
    return min(root->data,min(leftmin,rightmin));
}
int maxTree(node*root)
{
    if(root==NULL)
        return INT_MIN;
    int leftmax=maxTree(root->left);
    int rightmax=maxTree(root->right);
    return max(root->data,max(leftmax,rightmax));
}
bool isBST(node*root)
{
    if(root==NULL)
        return true;
    int leftmax=maxTree(root->left);
    int rightmin=minTree(root->right);
    if(root->data<leftmax || root->data>rightmin)
        return false;
    return isBST(root->left) && isBST(root->right);
}
int main()
 {
     node*root=levelWiseInput();
     if(isBST(root))
        cout<<"true";
     else
        cout<<"false";

}
