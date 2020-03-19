 #include<iostream>
 using namespace std;
 int fibI(int n)
 {
     int i;
     int dp[n+1];
     for(i=0;i<=n;i++)
     {
         dp[i]=0;
     }
     dp[0]=0;
     dp[1]=1;
     i=2;
     for(i=2;i<=n;i++)
     {
         dp[i]=dp[i-1]+dp[i-2];
     }
     return dp[n];
 }
 int main()
 {
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     int ans=fibI(n);
     cout<<ans;
 }
