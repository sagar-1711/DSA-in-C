#include<iostream>
#include<cstring>
using namespace std;
int lcs(string s1,string s2)
{
    int i,j;
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(i=m-1;i>=0;i--)
    {
         for(j=n-1;j>=0;j--)
         {
             if(s1[i]==s2[j])
                dp[i][j]=1+dp[i+1][j+1];
             else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
         }

    }
    return dp[0][0];

}

int main()
{

    string s1;
    string s2;
    cout<<"enter string 1"<<endl;
    cin >> s1;
    cout<<"enter string 2"<<endl;
    cin >> s2;
    int ans=lcs(s1,s2);
    cout<<"length of LCS = "<<ans;

}
