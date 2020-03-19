#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minStepsTo1(int n)
{
    int ans1,ans2,ans3;
    ans1=ans2=ans3=INT_MAX;
    if(n==1)
        //minimum steps from 1 to 1 is 0
        return 0;
    if(n%3==0)
        ans1=minStepsTo1(n/3);
    if(n%2==0)
        ans2=minStepsTo1(n/2);
    ans3=minStepsTo1(n-1);

    int ans=1+min(ans1,min(ans2,ans3));
    return ans;

}

int main()
{
     int n;
     cout<<"enter n"<<endl;
     cin>>n;
     int ans=minStepsTo1(n);
     cout<<"minimum steps from "<<n<<" to 1 are "<<ans;

}
