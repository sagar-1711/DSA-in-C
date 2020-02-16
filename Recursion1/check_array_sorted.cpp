#include<iostream>
using namespace std;
bool sorted(int arr[],int n)
{
    if(n==0 || n==1)
        return true;
    if(arr[0]>arr[1])
        return false;
    bool s=sorted(arr+1,n-1);
    return s;

}
int main()
{   int n;
    cout<<"\n enter the value of n";
    cin>>n;
    int*arr=new int[n];
    cout<<"enter array ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool s=sorted(arr,n);
    if(s==true)
        cout<<"array is sorted \n";
    else
        cout<<"array is not sorted";
    return 0;
}
