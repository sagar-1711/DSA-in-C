//O(n^2)
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
int height(node*root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
#include<vector>
void rootToLeafPathsSumToK(node*root,vector<int> &path,int k)
{
    if(root==NULL)
        return;
    k=k-root->data;
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        if(k==0)
        {
           for(int i=0;i<path.size();i++)
           {
               cout<<path[i]<<" ";

           }
           cout<<endl;
           return;

        }
        else
        {
            path.pop_back();
            return;

        }


    }
    rootToLeafPathsSumToK(root->left,path,k);
    rootToLeafPathsSumToK(root->right,path,k);
    path.pop_back();


}



int main()
{   int k;
    cout<<"enter sum \n"<<endl;
    cin>>k;
    cout<<"enter nodes of binary tree";
    vector<int> path;
    node*root=treeInput();
    printTreeDetailed(root);
    rootToLeafPathsSumToK(root,path,k);


}
