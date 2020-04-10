//O(n)
#include<iostream>
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
node*treeInput()
{   int data;
    cin>>data;
    if(data==-1)
        return NULL;
    node*root=new node(data);
    root->left=treeInput();
    root->right=treeInput();
    return root;

}
void printTreeDetailed(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
        cout<<"L"<<root->left->data<<",";
    if(root->right!=NULL)
        cout<<"R"<<root->right->data<<" ";
    cout<<endl;
    printTreeDetailed(root->left);
    printTreeDetailed(root->right);

}

int diameter2(node*root,int*h)
{   int lh=0,rh=0;
    if(root==NULL)
    {
        *h=0;
        return 0;//diameter is also 0
    }



    int option2=diameter2(root->left,&lh);
    int option3=diameter2(root->right,&rh);
    //since lh and rh gets calculated after calling option2 & option3,so we have to calculate option1 after other two options.
    int option1=1+lh+rh;
    *h=1+max(lh,rh);
    return max(option1,max(option2,option3));

}

int main()
{
    int height=0;
    node*root=treeInput();
    printTreeDetailed(root);
    cout<<diameter2(root,&height);


}
