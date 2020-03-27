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
    for(i=1;i<=m;i++)
    {
         for(j=1;j<=n;j++)
         {
             if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
             else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         }

    }
    return dp[m][n];
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

