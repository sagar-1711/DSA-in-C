#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int*weights,int*values,int n,int W)
{
    int i,j,ans,ans1,ans2;
    int dp[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            dp[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(j<weights[i-1])//j is max weight
                ans=dp[i-1][j];
            else
            {
                ans1=values[i-1]+dp[i-1][j-weights[i-1]];
                ans2=dp[i-1][j];
                ans=max(ans1,ans2);
            }
            dp[i][j]=ans;
        }
    }
    return dp[n][W];


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
    cout<<knapsack(weights,values,n,W);

}
