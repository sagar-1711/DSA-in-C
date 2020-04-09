#include<iostream>
#include<queue>
using namespace std;
void displayQueue(queue<int> q)
{
    int n=q.size();
    for(int i=q.front();i<=q.back();i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

}
int main()
{
    queue<int> q;
    q.push(1);
    displayQueue(q);
    q.push(2);
    displayQueue(q);
    q.push(3);
    displayQueue(q);
    q.push(4);
    displayQueue(q);
    q.push(5);
    displayQueue(q);
    q.pop();
    displayQueue(q);
    q.pop();
    displayQueue(q);

}
