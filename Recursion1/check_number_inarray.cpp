#include<iostream>
using namespace std;
bool findx(int arr[],int n,int x)
{
    if(n==0)
        return false;
    if(arr[0]==x)
        return true;

    bool s=findx(arr+1,n-1,x);
    return s;

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
    bool s=findx(arr,n,x);
    if(s==true)
        cout<<x<<" is present in array\n";
    else
        cout<<x<<"is not present in array\n";
}
