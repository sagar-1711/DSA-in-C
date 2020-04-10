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
node*buildTreePreIn(int*inorder,int*preorder,int inS,int inE,int preS,int preE)
{
    if(inS>inE)
        return NULL;
    int rootdata=preorder[preS];
    node*root=new node(rootdata);
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootIndex=i;
            break;
        }
    }
    int linS=inS;
    int linE=rootIndex-1;
    int rinS=rootIndex+1;
    int rinE=inE;
    int lpreS=preS+1;
    int lpreE=lpreS+(linE-linS);
    int rpreS=lpreE+1;
    int rpreE=preE;
    root->left=buildTreePreIn(inorder,preorder,linS,linE,lpreS,lpreE);
    root->right=buildTreePreIn(inorder,preorder,rinS,rinE,rpreS,rpreE);
    return root;
}
node*buildTreePreIn(int *inorder,int *preorder,int size)
{
    return buildTreePreIn(inorder,preorder,0,size-1,0,size-1);
}

int main()
{
    int size;
    cout<<"enter number of nodes"<<endl;
    cin>>size;
    int*preorder=new int[size];
    int*inorder=new int[size];
    cout<<"enter inorder"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>inorder[i];
    }
    cout<<"enter preorder"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>preorder[i];
    }
    node*root=buildTreePreIn(inorder,preorder,size);
    printLevelWise(root);
}
