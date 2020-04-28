#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> kLargest(int input[], int n, int k)
{
    //We use minHeap
    priority_queue <int, vector<int>, greater<int> > pq;
    vector<int> ans;
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
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;

}

int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

	return 0;
}
