#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
   int i;
   for(i=1;i<=n-1;i++)
   {   int value=arr[i];
       int hole=i;
       while(hole>0 && arr[hole-1]>value)
       {
           arr[hole]=arr[hole-1];
           hole--;
       }
       arr[hole]=value;
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
    insertion_sort(arr,n);
    cout<<"sorted array"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}
