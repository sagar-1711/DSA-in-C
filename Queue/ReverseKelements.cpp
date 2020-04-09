#include <cmath>
#include <iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reverseKElements(queue<int> q, int k)
{
    if(q.empty() || k>q.size() || k<=1)
        return q;
    int i;
    int n=q.size();
    stack<int> s;
    for(i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    for(i=0;i<k;i++)
    {
        q.push(s.top());
        s.pop();
    }
    for(i=0;i<n-k;i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main() {
	int n=0;
	cin>>n;
	queue<int> Queue;
	for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            Queue.push(temp);
        }
	int k;
	cin>>k;
	queue<int> ans = reverseKElements(Queue,k);
	while (!ans.empty())
        {
        	cout << ans.front() <<" ";
        	ans.pop();
    	}
}


