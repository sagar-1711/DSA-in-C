#include<climits>
#include<algorithm>
#include<iostream>
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
class PairAns {
    public :
    int mini;
    int maxi;
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
PairAns minMax(node*root)
{
    PairAns m;
    m.mini=INT_MAX;
    m.maxi=INT_MIN;
    if(root==NULL)
        return m;
    PairAns left=minMax(root->left);
    PairAns right=minMax(root->right);
    m.maxi=max(max(left.maxi,right.maxi),root->data);
    m.mini=min(min(left.mini,right.mini),root->data);
    return m;


}



int main()
{

    node*root=treeInput();
    PairAns ans = minMax(root);
    cout << ans.maxi << " " << ans.mini<< endl;

}
