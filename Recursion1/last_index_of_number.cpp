#include<iostream>
using namespace std;
int lastx(int arr[],int n,int x,int ei)
{   int index;
    if(ei==0)
        return -1;
    if (arr[ei]==x)
        return ei;
    index=lastx(arr,n,x,ei-1);
    return index;


}
int main()
{   int n,x;
    cout<<"\n enter the value of n=";
    cin>>n;
    cout<<"\n enter the value of x=";
    cin>>x;
    int*arr=new int[n];
    cout<<"enter array ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index=lastx(arr,n,x,n-1);
    cout<<"\n "<<index;


}
