#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int,bool> map;
    unordered_map

    <int,int> element_to_index_mapping;

    vector<int> ans;
    if(n==0)
    {
        ans.push_back(0);
        return ans;

    }
    for(int i=0;i<n;i++)
    {
        map[arr[i]]=true;
        element_to_index_mapping[arr[i]]=i;
    }

    int max_len=0;
    int max_start_index=0;
    int start_index=0;
    for(int i=0;i<n;i++)
    {
        start_index=i;

        int len=0;
        int k=arr[i];
        map[k]=false;
        len++;
        k++;
        while(map[k]==true)
        {
            map[k]=false;
			len++;
            k++;



        }
        int m=arr[i]-1;
        while(map[m]==true)
        {
            map[m]=false;
            len++;
            start_index=element_to_index_mapping[m];
            m--;

        }

        if(len>max_len)
        {
            max_len=len;
            max_start_index=start_index;
        }
        else if(len==max_len && start_index<max_start_index)
        {
            max_start_index=start_index;
        }

    }

    int max_start=arr[max_start_index];
    while(max_len--)
    {
        ans.push_back(max_start);
        max_start++;
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}
