#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int*weights,int*values,int n,int W,int i)
{
    int ans,ans1,ans2;
    if(i==n || W==0)
        return 0; //if we reach end of array then maximum value will be 0
    if(weights[i]>W)
        ans=knapsack(weights,values,n,W,i+1);
    else
    {
        //inclusion of ith term
        ans1=values[i]+knapsack(weights,values,n,W-weights[i],i+1);
        //exclusion of ith term
        ans2=knapsack(weights,values,n,W,i+1);
        ans=max(ans1,ans2);
    }
    return ans;


}
int main()
{
    int i,n,W;
    cout<<"Enter length"<<endl;
    cin>>n;
    int*weights=new int[n];
    cout<<"Enter weight array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    int*values=new int[n];
    cout<<"Enter value array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>values[i];
    }
    cout<<"Enter max Weight"<<endl;
    cin>>W;
    cout<<knapsack(weights,values,n,W,0);


}
