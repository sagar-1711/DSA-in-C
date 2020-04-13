#include<iostream>
#include<algorithm>
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
class BST
{
public:
    node*root;
    BST()
    {
        root=NULL;
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
    void printTree()
    {
        cout<<endl;
        return printTreeDetailed(root);
    }
    node*insert(node*temp,int data)
    {
        if(temp==NULL)
        {
            //BST is empty so create new node and return it
            node*newNode=new node(data);
            return newNode;
        }
        if(data<temp->data)
            temp->left=insert(temp->left,data);
        else
            temp->right=insert(temp->right,data);
        return temp;
    }
    void insert(int data)
    {
        root=insert(root,data);
    }
    node*deletenode(node*temp,int data)
    {
        if(temp==NULL)
            return NULL;
        if(data<temp->data)
        {
            temp->left=deletenode(temp->left,data);
            return temp;
        }
        if(data>temp->data)
        {
            temp->right=deletenode(temp->right,data);
        }

        //if we reach here then it means that data is neither less than temp->data nor >temp->data so temp->data==data
        else
        {
             //if temp is a leaf
            if(temp->left==NULL && temp->right==NULL)
            {
                return NULL;
            }
            //temp has one child
            else if(temp->left==NULL)
            {
                return temp->right;
            }
            else if(temp->right==NULL)
            {
                return temp->left;
            }
            //temp has two children
            else
            {
                node*minNode=temp->right;
                while(minNode->left!=NULL)
                {
                    minNode=minNode->left;
                }
                int rightmin=minNode->data;
                temp->data=rightmin;
                //now replace temp
                temp->right=deletenode(temp->right,rightmin);
                return temp;
            }

        }

    }
    void deletenode(int data)
    {
        root=deletenode(root,data);
    }
    bool hasData(node*temp,int data)
    {
        if(temp==NULL)
            return false;
        if(temp->data==data)
            return true;
        if(data<temp->data)
            return hasData(temp->left,data);
        else
            return hasData(temp->right,data);
        return false;

    }
    bool hasData(int data)
    {
        return hasData(root,data);
    }
};
int main()
{
    //All operations are O(height)
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(6);
    b.insert(8);
    b.insert(12);
    b.insert(11);
    b.insert(15);
    b.printTree();
    b.deletenode(8);
    b.printTree();
    b.deletenode(5);
    b.printTree();
    b.deletenode(10);
    b.printTree();

}
