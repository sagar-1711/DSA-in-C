#include<iostream>
#include<stack>
using namespace std;
void displayStack(stack<int> s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    displayStack(s);
    s.pop();
    displayStack(s);
    cout<<s.top()<<endl;;
    cout<<s.empty();


}
