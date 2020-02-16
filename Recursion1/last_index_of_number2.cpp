#include<iostream>
using namespace std;
int lastx(int arr[],int n,int x)
{   int index;
    if(n==0)
        return -1;
    index=lastx(arr+1,n-1,x);
    if(index==-1)
    {
        if(arr[0]==x)
            return 0;
        else
            return -1;
    }
    return 1+index;

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
    int index=lastx(arr,n,x);
    cout<<"\n "<<index;


}
