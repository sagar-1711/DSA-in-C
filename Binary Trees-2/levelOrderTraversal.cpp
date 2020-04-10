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
void LevelOrderTraversal(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty())
    {
        node*curr=q.front();
        q.pop();
        if(curr!=NULL)
        {
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        else
        {
            q.push(NULL);
            cout<<endl;
        }
        if(q.size()==1 && q.front()==NULL)
            break;
    }

}

int main()
{
    node*root=levelWiseInput();
    LevelOrderTraversal(root);
}
