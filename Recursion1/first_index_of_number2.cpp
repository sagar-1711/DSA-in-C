#include<iostream>
using namespace std;
int findx(int arr[],int n,int x,int si)
{
    if(si==n-1)
        return -1;
    if(arr[si]==x)
        return si;
    return findx(arr,n,x,si+1);

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
    int index=findx(arr,n,x,0);
    cout<<"\n "<<index;


}
