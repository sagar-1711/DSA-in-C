#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int buyTicket (int *arr, int n, int k)
{
    //max Heap
    priority_queue<int> pq;
    queue<int> q;
    //storing elemnts into priority queue
     //we will store indices in queue
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }

    int time=0;
    while(time<n)
    {
        if(pq.top()==arr[k] && q.front()==k)
        {
            time++;
            break;
        }
        if(arr[q.front()]<pq.top())
        {
            int front=q.front();
            q.push(front);
            q.pop();
        }
        else
        {
            time++;
            q.pop();
            pq.pop();
        }
    }
    return time;
}


int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}
