#include <bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
using namespace std;
void pairSum(int *input, int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        int count;
        int k=input[i];
        if(m[k]>0 && m[-k]>0)
        {
            if(k==0)
            {
                count=m[k];
            }
            else
            {
                count=m[k]*m[-k];
            }

            while(count!=0)
            {
                cout<<min(k,-k)<<" "<<max(k,-k)<<endl;
                count--;
            }
        	m[k]=0;
            m[-k]=0;
        }
    }


}


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}
