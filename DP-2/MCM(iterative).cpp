#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mcm(int p[],int n)
{
    //increasing n for simplifying calculation
    n++;
    int L,i,j,k,ans;
    //0th row and coloumn are not used;
    int dp[n][n];
    for(i=1;i<n;i++)
    {
        dp[i][i]=0;
    }
    for(L=2;L<=n-1;L++)
    {
        for(i=1;i<=n-L;i++)
        {
            j=i+L-1;
            dp[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                ans=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                dp[i][j]=min(ans,dp[i][j]);
            }
        }
    }
   return dp[1][n-1];


}
int main()
{
    int n;
    cout<<"Enter number of matrices"<<endl;
    cin >> n;
    int p[n+1];
    for(int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << mcm(p,n);
}


