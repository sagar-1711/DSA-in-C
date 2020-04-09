#include<iostream>
#include<queue>
using namespace std;
class Stack
{
public:
    queue<int> q1;
    queue<int> q2;
    bool isEmpty()
    {
        if(q1.empty())
            return true;
        return false;
    }
    int size()
    {
        return q1.size();
    }
    void push(int data)
    {
        q1.push(data);
    }
    void pop()
    {
        while((q1.size())!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top()
    {
        return q1.back();
    }
};
void print(Stack s)
{
    queue<int> q=s.q1;
    while(q.size()!=0)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;


}
int main()
{
    Stack s;
    s.push(1);
    print(s);
    s.push(2);
    print(s);
    s.push(3);
    print(s);
    s.push(4);
    print(s);
    s.push(5);
    print(s);
    s.pop();
    print(s);
    s.pop();
    print(s);

}
