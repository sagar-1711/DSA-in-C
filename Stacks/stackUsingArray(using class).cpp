#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Stack
{
    private:
        int A[MAX_SIZE];
        int top;
    public:
        //constructor
        Stack()
        {
            top=-1;//for an empty array set top as -1,whenever a new object of class is created
        }
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
};
int main()
{
     //O(1)
    Stack S;
    S.push(2);
    S.print();
	S.push(5);
	S.print();
	S.push(10);
	S.print();
	S.pop();
	S.print();
	S.push(12);
	S.print();
}
