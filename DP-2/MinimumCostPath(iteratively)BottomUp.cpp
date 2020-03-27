#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define M 3
#define N 3
int minCostPath(int input[M][N])
{
    int i,j;
    int dp[M+1][N+1];
    int ans1,ans2,ans3,ans;
    for(i=0;i<=M;i++)
    {
        for(j=0;j<=N;j++)
        {
            dp[i][j]=INT_MAX;
        }

    }
    for(i=M-1;i>=0;i--)
    {
         for(j=N-1;j>=0;j--)
        {
            if(i==M-1 && j==N-1)
            {
                dp[i][j]=input[i][j];
            }
            else
            {
                ans1=dp[i][j+1];
                ans2=dp[i+1][j];
                ans3=dp[i+1][j+1];
                dp[i][j]=input[i][j]+min(ans1,min(ans2,ans3));
            }
        }

    }
    return dp[0][0];
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
