#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int dp[1000];
int minStepsTo1(int n)
{
    int ans1,ans2,ans3;
    ans1=ans2=ans3=INT_MAX;
    //minimum steps from 1 to 1 is 0
    if(n==1)
        return 0;
    if(n%3==0)
        {
            if(dp[n/3]==-1)
            {
                ans1=minStepsTo1(n/3);
                dp[n/3]=ans1;
            }
            else
            {
                 ans1=dp[n/3];
            }
        }
     if(n%2==0)
        {
            if(dp[n/2]==-1)
            {
                ans2=minStepsTo1(n/2);
                dp[n/2]=ans2;
            }
            else
            {
                 ans2=dp[n/2];
            }

        }

    if(dp[n-1]==-1)
        {
            ans3=minStepsTo1(n-1);
            dp[n-1]=ans3;
        }
    else
        {
            ans3=dp[n-1];

        }


    int ans=1+min(ans1,min(ans2,ans3));
    return ans;

}

int main()
{
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     for(int i=0;i<=n;i++)
     {
         dp[i]=-1;
     }
     int ans=minStepsTo1(n);
     cout<<"minimum steps from "<<n<<" to 1 are "<<ans;

}
