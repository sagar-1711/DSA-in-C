#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mcm(int p[],int s,int e)
{
    if(s==e)
        return 0;
    int min_value=INT_MAX;
    for(int k=s;k<e;k++)
    {
        int ans1=mcm(p,s,k);
        int ans2=mcm(p,k+1,e);
        int cost=p[s-1]*p[k]*p[e];
        int curr_value=ans1+ans2+cost;
        min_value=min(min_value,curr_value);

    }
    return min_value;
}
int main()
{
    int n;
    cout<<"Enter number of matrices"<<endl;
    cin >> n;
    int p[n+1];
    for(int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << mcm(p,1,n);
}


