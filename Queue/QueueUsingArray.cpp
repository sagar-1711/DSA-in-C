#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Queue
{
private:
    int A[MAX_SIZE];
    int fron;
    int rear;
    int coun;
public:
    Queue()
    {
        fron=-1;
        rear=-1;
        coun=0;
    }
    int size()
    {
        return coun;
    }
    int isEmpty()
    {
        if(fron==-1 && rear==-1)
            return true;
        return false;
    }
    void enqueue(int x)
    {
        if(rear==MAX_SIZE-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(isEmpty())
        {
           fron=rear=0;
           A[rear]=x;
           coun++;
        }
        else
        {

            rear++;
            A[rear]=x;
            coun++;
        }


    }
    void dequeue()
   {
       if(isEmpty())
       {
           cout<<"Queue is empty"<<endl;
           return;
       }
       else if(fron==rear)
       {
           fron=rear=-1;
           coun--;
       }
       else
       {
           fron++;
           coun--;
       }
   }
   void print()
   {
       cout<<endl;
       for(int i=fron;i<=rear;i++)
        cout<<A[i]<<" ";
   }

};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
    q.print();
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();
    cout<<endl<<q.size();
    q.dequeue();
    q.print();
    cout<<endl<<q.size();




}
