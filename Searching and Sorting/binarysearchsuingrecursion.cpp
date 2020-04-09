//return -1 if element is not present else return index of element
#include<iostream>
using namespace std;
int binarysearch(int arr[],int x,int si,int ei)
{
    if (si>ei)
            return -1;
    int mid=(si+ei)/2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid]>x)
        return binarysearch(arr,x,si,mid-1);
    else
        return binarysearch(arr,x,mid+1,ei);

}
int main()
{   int arr[100];
    int len;
    int x;
    cout<<"\n enter length of array=";
    cin>>len;
    cout<<"\n Enter array=";
    for(int i=0;i<len;i++)
        cin>>arr[i];
    cout<<"\n enter element=";
    cin>>x;
    int index=binarysearch(arr,x,0,len-1);
    (index==-1)?cout<<x<<" is not present in array ":cout<<x<<" is present at index="<<index;
    return 0;
}
