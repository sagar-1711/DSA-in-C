
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
void preOrder(node*root)
{
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

node*constructTreeHelper(int*input,int si,int ei)
{
    if(si>ei)
        return NULL;
    int mid=(si+ei)/2;
    node*root=new node(input[mid]);
    root->left=constructTreeHelper(input,si,mid-1);
    root->right=constructTreeHelper(input,mid+1,ei);
    return root;

}
node*constructTree(int *input, int n)
{
	return constructTreeHelper(input,0,n-1);

}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];

    for(int i=0;i<size;i++)
        cin>>input[i];

    node*root = constructTree(input, size);
    preOrder(root);

}

