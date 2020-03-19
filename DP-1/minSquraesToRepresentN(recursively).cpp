#include<iostream>
using namespace std;
#include<algorithm>

int minSquaresToN(int n)
{
    if(n==0)
        return 0;
    int i;
    int ans=n;//maximum ans can be n;
    for(i=1;i*i<=n;i++)
    {
        int currAns=1+minSquaresToN(n-i*i);
        ans=min(ans,currAns);
    }
    return ans;
}
int main()
{
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     int ans=minSquaresToN(n);
     cout<<ans;

}
