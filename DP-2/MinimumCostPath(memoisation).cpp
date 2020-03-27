#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define M 3
#define N 3
int dp[M][N];
int minCostPath(int input[M][N],int i,int j)
{
    int ans1,ans2,ans3,ans;
    if(i==M-1 && j==N-1)
        return input[i][j];
    if(i>=M || j>=N)
        return INT_MAX;
    if(dp[i][j+1]==INT_MAX)
    {
        ans1=minCostPath(input,i,j+1);
        dp[i][j+1]=ans1;

    }
    else
        ans1=dp[i][j+1];
    if(dp[i+1][j]==INT_MAX)
    {
        ans2=minCostPath(input,i+1,j);
        dp[i+1][j]=ans2;
    }
    else
        ans2=dp[i+1][j];
    if(dp[i+1][j+1]==INT_MAX)
    {
        ans3=minCostPath(input,i+1,j+1);
        dp[i+1][j+1]=ans3;
    }
    else
        ans3=dp[i+1][j+1];
    ans=input[i][j]+min(ans1,min(ans2,ans3));
    return ans;
}


int main()
{
    int i,j;
    int input[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>input[i][j];
        }
    }
    for(i=0;i<=M;i++)
    {
          for(j=0;j<=N;j++)
        {
            dp[i][j]=INT_MAX;
        }

    }
    cout<<minCostPath(input,0,0);

}
