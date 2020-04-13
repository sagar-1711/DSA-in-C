#include<iostream>
#include<queue>
#include<vector>
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
bool nodeToRootPath(node*root,vector<int> &arr,int x)
{
    if(root==NULL)
        return false;

    if(root->data==x)
    {
        arr.push_back(root->data);
        return true;
    }
    if(nodeToRootPath(root->left,arr,x) || nodeToRootPath(root->right,arr,x))
    {
        arr.push_back(root->data);
        return true;
    }
    else
        return false;


}
int main()
{
    int x;
    node*root=levelWiseInput();
    cin>>x;
    vector<int> arr;
    if (nodeToRootPath(root, arr, x))
    {
        for (int i=0; i<arr.size(); i++)
            cout << arr[i] << " ";

    }
    else
        cout << "No Path";
}

