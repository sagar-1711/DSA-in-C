#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthLargest(vector<int> input, int n, int k)
{
  	//We use min priority queue
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
	for(int i=k;i<n;i++)
    {
        if(pq.top()<input[i])
        {
            pq.pop();
            pq.push(input[i]);
        }
        else
            continue;
    }
    return pq.top();

}


int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}
