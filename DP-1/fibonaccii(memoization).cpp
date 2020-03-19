 #include<iostream>
 using namespace std;
 int dp[101];
 int fib(int n)
 {
    int ans1,ans2;
    if(n==0 || n==1)
        return n;
    if(dp[n-1]==-1)
    {
        ans1=fib(n-1);
        dp[n-1]=ans1;
    }
    else
        ans1=dp[n-1];
    if(dp[n-2]==-1)
    {
        ans2=fib(n-2);
        dp[n-2]=ans1;
    }
    else
        ans2=dp[n-2];

    int ans=ans1+ans2;
    return ans;
 }
 int main()
 {
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     for(int i=0;i<=100;i++)
     {
         dp[i]=-1;
     }
     int ans=fib(n);
     cout<<ans;
 }
