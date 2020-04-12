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
bool isBSTHelper(node*root,int*Min,int*Max)
{
    if(root==NULL)
    {
        *Min=INT_MAX;
        *Max=INT_MIN;
        return true;
    }
    bool isLeftBST=isBSTHelper(root->left,Min,Max);
    int leftMin=*Min;
    int leftMax=*Max;
    bool isRightBST=isBSTHelper(root->right,Min,Max);
    int rightMin=*Min;
    int rightMax=*Max;
    *Min=min(root->data,min(leftMin,rightMin));
    *Max=max(root->data,max(leftMax,rightMax));
    if(!(isLeftBST&&isRightBST))
        return false;
    if(root->data<leftMax || root->data>rightMin)
        return false;
    return true;





}
bool isBST(node*root)
{
    int Max,Min;
    return isBSTHelper(root,&Max,&Min);

}
int main()
 {
     node*root=levelWiseInput();
     if(isBST(root))
        cout<<"true";
     else
        cout<<"false";

}
