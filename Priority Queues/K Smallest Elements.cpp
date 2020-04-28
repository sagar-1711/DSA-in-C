#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> kSmallest(int *input, int n, int k)
{
    //We use maxHeap
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
	for(int i=k;i<n;i++)
    {
        if(pq.top()>input[i])
        {
            pq.pop();
            pq.push(input[i]);
        }
        else
            continue;
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}
