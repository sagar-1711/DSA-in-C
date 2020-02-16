#include<iostream>
using namespace std;
int sum_of_array(int arr[],int n)
{
    if(n==1)
        return arr[0];
    int sum=arr[0]+sum_of_array(arr+1,n-1);
    return sum;
}
int main()
{   int n;
    cout<<"\n enter the value of n=";
    cin>>n;
    int*arr=new int[n]; //  int arr[n];
    cout<<"enter array ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s=sum_of_array(arr,n);
    cout<<"sum is "<<s;
}
