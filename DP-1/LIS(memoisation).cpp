#include <iostream>
using namespace std;
#include<algorithm>
int dp[10000];
int lis( int arr[], int n, int *max_ref)
{
    if (n ==1)
        return 1;
    int res, max_ending_here = 1;
    for (int i =1; i < n; i++)
    {
        res = lis(arr, i , max_ref);
        if (arr[i]>arr[i-1])
        {
            if(dp[i]==-1)
            {
                max_ending_here = res + 1;
                dp[i]=max_ending_here;
            }
            else
            {
                max_ending_here=dp[i];
            }
        }

    }

    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;
    return max_ending_here;
}



int main()
{
    int n,i;
    cout<<"Enter length of array:"<<endl;
    cin >> n;
    int overallmax=0;
    int arr[100000];
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0;i<n;i++)
    {
        dp[i]=-1;
    }
    int ans=lis(arr,n,&overallmax);
    cout<<dp[n-1];
}

