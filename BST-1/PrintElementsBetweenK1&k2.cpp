
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
void elementsInRangeK1K2(node* root, int k1, int k2)
{
    if(root==NULL)
        return;
    if(root->data<k1)
        elementsInRangeK1K2(root->right,k1,k2);
    else if(root->data>k2)
        elementsInRangeK1K2(root->left,k1,k2);
	else
    {

        elementsInRangeK1K2(root->left,k1,k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right,k1,k2);

    }

}
int main()
{
    node*root=levelWiseInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}
