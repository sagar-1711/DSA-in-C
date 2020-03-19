#include<iostream>
using namespace std;
#include<algorithm>
int minSquaresToN(int n)
{
     int dp[n+1],i,j,ans,currans;
     for(int i=0;i<=n;i++)
     {
         dp[i]=0;
     }
     dp[0]=0;
    for(i=1;i<=n;i++)
    {
        ans=n;
        for(j=1;i>=j*j;j++)
        {
            currans=1+dp[i-(j*j)];
            ans=min(ans,currans);
        }
        dp[i]=ans;

    }
    return dp[n];

}
int main()
{
     int n;
     cin>>n;
     int ans=minSquaresToN(n);
     cout<<ans<<endl;

}
