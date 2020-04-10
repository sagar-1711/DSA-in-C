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
node*buildTreePosIn(int*inorder,int*postorder,int inS,int inE,int posS,int posE)
{
    if(inS>inE)
        return NULL;
    int rootdata=postorder[posE];
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
    int lposS=posS;
    int lposE=lposS+(linE-linS);
    int rposS=lposE+1;
    int rposE=posE-1;
    root->left=buildTreePosIn(inorder,postorder,linS,linE,lposS,lposE);
    root->right=buildTreePosIn(inorder,postorder,rinS,rinE,rposS,rposE);
    return root;
}
node*buildTreePostIn(int *inorder,int *postorder,int size)
{
    return buildTreePosIn(inorder,postorder,0,size-1,0,size-1);
}

int main()
{
    int size;
    cout<<"enter number of nodes"<<endl;
    cin>>size;
    int*postorder=new int[size];
    int*inorder=new int[size];
    cout<<"enter inorder"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>inorder[i];
    }
    cout<<"enter postorder"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>postorder[i];
    }
    node*root=buildTreePosIn(inorder,postorder,size);
    printLevelWise(root);
}
