#include<iostream>
#include<cstring>
using namespace std;
int dp[100][100];
int lcs(string s1,string s2,int i,int j)
{
    int ans,ans1,ans2;
    if(i==s1.size() || j==s2.size())
        return 0;
    if(s1[i]==s2[j])
    {
        if(dp[i+1][j+1]==-1)
        {
            dp[i+1][j+1]=lcs(s1,s2,i+1,j+1);
            ans=1+dp[i+1][j+1];
        }
        else
            ans=1+dp[i+1][j+1];
    }

    else
        {
            if(dp[i+1][j]==-1)
            {
                dp[i+1][j]=lcs(s1,s2,i+1,j);
                ans1=dp[i+1][j];
            }
            else
                ans1=dp[i+1][j];

            if(dp[i][j+1]==-1)
            {
                dp[i][j+1]=lcs(s1,s2,i,j+1);
                ans2=dp[i][j+1];
            }
            else
                ans2=dp[i][j+1];
            ans=max(ans1,ans2);
        }
    return ans;
}
int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    string s1;
    string s2;
    cout<<"enter string 1"<<endl;
    cin >> s1;
    cout<<"enter string 2"<<endl;
    cin >> s2;
    int ans=lcs(s1,s2,0,0);
    cout<<"length of LCS = "<<ans;

}
