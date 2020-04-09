#include<iostream>
#include <stack>
using namespace std;
void reverseStack(stack<int>&s1,stack<int>&s2)//here we have used reference so that any change in s1 will also reflect in value of s1 in main
{
    if(s1.size()==1 || s1.size()==0)
        return;
    int x=s1.top();
    s1.pop();
    reverseStack(s1,s2);
    //copy elements to s2
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    //copy x to s1;
    s1.push(x);
    //copy elements back to s1 from s2;
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    stack<int> s1,s2;
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        s1.push(ele);
    }
    reverseStack(s1,s2);
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }

}
