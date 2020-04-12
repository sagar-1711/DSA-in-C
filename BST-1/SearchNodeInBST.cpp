
#include<iostream>
#include<queue>
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
node*searchInBST(node*root , int k)
{
  	if(root==NULL)
        return NULL;//node is not present in BST
    if(root->data==k)
        return root;
    if(k<root->data)
       return searchInBST(root->left,k);
    else
        return searchInBST(root->right,k);

}
int main()
{
    node*root=levelWiseInput();
    int k;
    cin >> k;
    node*ans = searchInBST(root, k);
    if(ans != NULL)
        {
            cout << ans -> data << endl;
        }
}
