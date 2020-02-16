#include<iostream>
using namespace std;
bool sorted(int arr[],int n,int si)
{
    if(si==n-1 || n==1)
        return true;
    if(arr[si]>arr[si+1])
        return false;
    bool s=sorted(arr,n,si+1);
    return s;

}
int main()
{   int n;
    cout<<"\n enter the value of n=";
    cin>>n;
    int*arr=new int[n];
    cout<<"enter array ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool s=sorted(arr,n,0);
    if(s==true)
        cout<<"array is sorted \n";
    else
        cout<<"array is not sorted";
    return 0;
}
