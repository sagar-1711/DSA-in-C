#include<iostream>
#include <cstdlib>
using namespace std;
class LL
{
    public:
        int data;
        LL*next=NULL;
};
LL*top=NULL;
void push(int x)
{
    LL*newNode=new LL();
    newNode->data=x;
    if(top==NULL)
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }


}
void pop()
{
    if(top==NULL)
    {
        cout<<"Stack is empty";
        return;
    }
    LL*temp=top;
    top=top->next;
    free(temp);
}
void print()
{
    LL*t=top;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
     cout<<endl;

}
int Top()
{
    return top->data;
}

bool isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

int main()
{
    push(1);
    print();
    push(2);
    print();
    push(3);
    print();
    pop();
    print();
    cout<<Top();

}
