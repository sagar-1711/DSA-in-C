#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int dp[100][100];
int mcm(int p[],int s,int e)
{
    if(s==e)
        return 0;
    int ans1,ans2,curr_value,cost;
    int min_value=INT_MAX;
    for(int k=s;k<e;k++)
    {
        if(dp[s][k]==-1)
        {
            ans1=mcm(p,s,k);
            dp[s][k]=ans1;

        }
        else
        {
            ans1=dp[s][k];

        }
        if(dp[k+1][e]==-1)
        {
            ans2=mcm(p,k+1,e);
            dp[k+1][e]=ans2;
        }
        else
        {
            ans2=dp[k+1][e];
        }
        cost=p[s-1]*p[k]*p[e];
        curr_value=ans1+ans2+cost;
        min_value=min(min_value,curr_value);

    }
    return min_value;
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
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }

    int ans=mcm(p,1,n);
    cout<<ans<<endl;

}


