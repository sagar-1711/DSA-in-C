#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node*next;
};
class Queue
{
public:
    Node* head=NULL;
    Node*tail=NULL;
    int count=0;
    int isEmpty()
    {
        if(count==0)
            return true;
        return false;
    }
    int size()
    {
        return count;
    }
    void enqueue(int x)
    {
        Node*newNode=new Node();
        newNode->data=x;
        if(head==NULL && tail==NULL)
        {
            head=tail=newNode;
            count++;

        }
        else
        {
            tail->next=newNode;
            tail=newNode;
            count++;
        }
    }
    void dequeue()
    {
        if(head==NULL)
        {
            cout<<"Queue is empty";
        }
        else
        {
            Node*temp=head;
            head=head->next;
            free(temp);
            count--;
        }
    }
    void print()
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    Queue q;
    q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
    q.print();
    cout<<q.size()<<endl;
    q.dequeue();
    q.print();
    cout<<q.size()<<endl;
    q.dequeue();
    q.print();
    cout<<q.size()<<endl;
    q.dequeue();
    q.print();
    cout<<q.size()<<endl;


}

