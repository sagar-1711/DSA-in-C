#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define M 3
#define N 3
int minCostPath(int input[M][N],int i,int j)
{
    if(i==M-1 && j==N-1)
        return input[i][j];
    if(i>=M || j>=N)
        return INT_MAX;
    int ans1=minCostPath(input,i+1,j);
    int ans2=minCostPath(input,i,j+1);
    int ans3=minCostPath(input,i+1,j+1);
    int ans=input[i][j]+min(ans1,min(ans2,ans3));
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
    cout<<minCostPath(input,0,0);

}
