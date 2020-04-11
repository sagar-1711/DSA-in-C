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

void printkdistanceNodeDown(node*root,int k)
{
    if (root == NULL || k < 0)
        return;
    if (k==0)
    {
        cout << root->data << endl;
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}
int  nodesAtDistanceK(node*root,int target,int k)
{

    if (root == NULL)
        return -1;
    if (root->data== target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl =   nodesAtDistanceK(root->left, target, k);
    if (dl != -1)
    {
         if (dl + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->right, k-dl-2);
         return 1 + dl;
    }

    int dr =  nodesAtDistanceK(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
}
int main()
 {
    node* root =levelWiseInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}


