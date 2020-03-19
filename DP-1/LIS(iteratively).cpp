#include <iostream>
using namespace std;
#include<algorithm>
int lis( int arr[], int n)
{
    int dp[n],i,j,possibleans,best=0;
    dp[0]=1;//LIS of array with one element =1
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            {
                 possibleans=dp[j]+1;
                if(possibleans>dp[i])
                {
                    dp[i]=possibleans;
                }
            }

        }
    }
    for(i=0;i<n;i++)
    {
        if(best<dp[i])
            best=dp[i];
    }
    return best;
}



int main()
{
    int n;
    cout<<"Enter length of array:"<<endl;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr,n);
}

