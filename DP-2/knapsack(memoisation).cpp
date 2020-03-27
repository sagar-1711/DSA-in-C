#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000][1000];
int knapsack(int*weights,int*values,int n,int W,int i)
{
    int ans,ans1,ans2,smallans;

    if(i==n-1 && W==0)
        return 0; //if we reach end of dp then maximum value will be -1
    if(weights[i]>W)
    {
        if(dp[i+1][W]==-1)
           {
             dp[i+1][W]=knapsack(weights,values,n,W,i+1);
             ans=dp[i+1][W];
           }
        else
            ans=dp[i+1][W];
    }
    else
    {
        //inclusion of ith term
        if(dp[i+1][W-weights[i]]==-1)
        {
            smallans=knapsack(weights,values,n,W-weights[i],i+1);
            dp[i+1][W-weights[i]]=smallans;
            ans1=values[i]+smallans;
        }
        else
            {
                ans1=values[i]+dp[i+1][W-weights[i]];
            }
        //exclusion of ith term
        if(dp[i+1][W]==-1)
        {
            ans2=knapsack(weights,values,n,W,i+1);
            dp[i+1][W]=ans2;

        }
        else
            {
                ans2=dp[i+1][W];
            }

        ans=max(ans1,ans2);

    }
    return ans;




}
int main()
{
    int i,j,n,W;
    cout<<"Enter length"<<endl;
    cin>>n;
    int*weights=new int[n];
    cout<<"Enter weight array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    int*values=new int[n];
    cout<<"Enter value array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>values[i];
    }
    cout<<"Enter max Weight"<<endl;
    cin>>W;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }

    }
    if(W==0)
        return 0;
    cout<<knapsack(weights,values,n,W,0);

}
