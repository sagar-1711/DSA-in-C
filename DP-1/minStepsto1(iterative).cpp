#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minStepsTo1(int n)
{
    int dp[n+1];
    int ans1,ans2,ans3;
    for(int i=0;i<=n;i++)
    {
         dp[i]=0;
    }
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=n;i++)
    {
        ans1=ans2=ans3=INT_MAX;
        if(i%3==0)
            ans1=dp[i/3];
        if(i%2==0)
            ans2=dp[i/2];
        ans3=dp[i-1];
        dp[i]=1+min(ans1,min(ans2,ans3));
    }
    return dp[n];
}

int main()
{
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     int ans=minStepsTo1(n);
     cout<<"minimum steps from "<<n<<" to 1 are "<<ans;

}
