#include<iostream>
using namespace std;
#define MAX_SIZE 100
int A[MAX_SIZE];
int top=-1;
bool isEmpty()
{
    if(top==-1)
        return true;
    return false;
}
void push(int value)
{
    if(top==MAX_SIZE-1)
    {
        cout<<"Error: Stack Overflow \n";
        return;
    }
    top++;
    A[top]=value;
}
void pop()
{
    if(isEmpty()==true)//top==-1
    {
        cout<<"Error: Stack is Empty, no element to pop \n";
        return;
    }
    top--;
}
int findtop()
{
    return A[top];
}
void print()
{
    cout<<"Stack: ";
    for(int i=0;i<=top;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //O(1)
    push(1);
    print();
    push(2);
    print();
    push(3);
    print();
    pop();
    print();
    cout<<findtop();
}
