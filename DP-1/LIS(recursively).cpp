#include <iostream>
using namespace std;
#include<algorithm>
int lis( int arr[], int n, int *max_ref)
{
    /* Base case */
    if (n ==1)
        return 1;

    // 'max_ending_here' is length of LIS ending with arr[n-1]
    int res, max_ending_here = 1;

    /* Recursively get all LIS ending with arr[0], arr[1] ...
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and
       max ending with arr[n-1] needs to be updated, then
       update it */
    for (int i =1; i < n; i++)
    {
        res = lis(arr, i , max_ref);
        if (arr[i]>arr[i-1])
            max_ending_here = res + 1;
    }

    // Compare max_ending_here with the overall max. And
    // update the overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;

    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}



int main()
{
    int n;
    cout<<"Enter length of array:"<<endl;
    cin >> n;
    int overallmax=0;
    int arr[100000];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr,n,&overallmax);
}

