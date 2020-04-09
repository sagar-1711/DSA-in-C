#include<iostream>
#include<stack>
using namespace std;
class Queue
{
public:
    stack<int> s1;
    stack<int> s2;
    bool isEmpty()
    {
        if(size()==0)
            return true;
        return false;
    }
    int size()
    {
        return s1.size();
    }
    void enqueue(int data)
    {
         s1.push(data);
    }
    int dequeue()
    {
        if(s1.size()==0)
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

};
void print(Queue q)
{
    while(!q.isEmpty())
    {
        cout<<q.dequeue()<<" ";

    }
    cout<<endl;

}
int main()
{
    Queue q;
    q.enqueue(1);
    print(q);
    q.enqueue(2);
    print(q);
    q.enqueue(3);
    print(q);
    q.enqueue(4);
    print(q);
    q.dequeue();
    print(q);
    q.dequeue();
    print(q);
    q.dequeue();
    print(q);
}
