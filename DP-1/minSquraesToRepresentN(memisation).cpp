#include<iostream>
using namespace std;
#include<algorithm>
int minSquaresToN(int n,int dp[])
{

    if(n==0)
        return 0;
    int i,currans;
    int ans=n;//maximum ans can be n;
    for(i=1;i*i<=n;i++)
    {
        int checkvalue=n-(i*i);
        if(dp[checkvalue]==-1)
        {
            int smallans=minSquaresToN(checkvalue,dp);
            dp[checkvalue]=smallans;
            currans=1+smallans;

        }
        else
        {
            currans=1+dp[checkvalue];

        }
         ans=min(ans,currans);

    }

    return ans;

}
int main()
{
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     int dp[n+1];
     for(int i=0;i<=n;i++)
     {
         dp[i]=-1;
     }
     int ans=minSquaresToN(n,dp);
     cout<<ans<<endl;

}
