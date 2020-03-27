#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define M 3
#define N 3
int dp[M+1][N+1];
int minCostPath(int input[M][N])
{
    int i,j;
    int ans1,ans2,ans3,ans;
    for(i=0;i<=M;i++)
    {
        for(j=0;j<=N;j++)
        {
            dp[i][j]=INT_MAX;
        }

    }
    for(i=1;i<=M;i++)
    {
         for(j=1;j<=N;j++)
        {
            if(i==1 && j==1)
            {
                dp[1][1]=input[0][0];
            }
            else
            {
                ans1=dp[i][j-1];
                ans2=dp[i-1][j];
                ans3=dp[i-1][j-1];
                dp[i][j]=input[i-1][j-1]+min(ans1,min(ans2,ans3));
            }
        }

    }
    return dp[M][N];
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
    cout<<minCostPath(input);


}
