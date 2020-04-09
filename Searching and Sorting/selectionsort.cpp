#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int imin=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[imin]>arr[j])
                imin=j;
        }
        int temp=arr[imin];
        arr[imin]=arr[i];
        arr[i]=temp;
    }
}
int main()
{
    int arr[100],n,i;
    cout<<"Enter the length of array"<<endl;
    cin>>n;
    cout<<"enter elements of arr"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);
    cout<<"sorted array"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}
