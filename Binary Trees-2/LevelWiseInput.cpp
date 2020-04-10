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
void printLevelWise(node*root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node*ele=q.front();
        q.pop();
        cout<<ele->data<<":";
        if(ele->left!=NULL)
        {
            node*leftchild=ele->left;
            cout<<"L"<<leftchild->data<<",";
            q.push(leftchild);
        }
        if(ele->right!=NULL)
        {
            node*rightchild=ele->right;
            cout<<"R"<<rightchild->data;
            q.push(rightchild);
        }
        cout<<endl;

    }

}

int main()
{
    node*root=levelWiseInput();
    printLevelWise(root);
}
