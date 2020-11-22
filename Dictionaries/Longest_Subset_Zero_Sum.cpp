#include <iostream>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size)
{
    unordered_map<int,int> m;
    int max_len=0;
    int cum_sum=0;
    for(int i=0;i<size;i++)
    {
        cum_sum+=arr[i];
        if(cum_sum==0)
        {
            if(i+1>max_len)
                max_len=i+1;

        }
        else if(m.count(cum_sum)>0)
        {
            int len=i-m[cum_sum];
            if(len>max_len)
            {
                max_len=len;
            }

        }
        else
        {
            m[cum_sum]=i;
        }
    }


    return max_len;
}




int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}

