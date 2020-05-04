#include <iostream>
#include<algorithm>
using namespace std;
void FindTriplet(int arr[], int size, int x)
{
	for(int k=0;k<size;k++)
    {
        sort(arr,arr+size);
        int si=k+1;
        int ei=size-1;
        int val=x-arr[k];
        while(si<ei)
        {
            if(arr[si]+arr[ei]<val)
                si++;
            else if(arr[si]+arr[ei]>val)
                ei--;
            else //if(arr[si]+arr[ei]==val)
            {
                int leftcount=1;
                int leftele=arr[si];
                while(arr[si+1]==arr[si])
                {
                    leftcount++;
                    si++;
                }
                int product;
                int rightcount=1;
                while(arr[ei-1]==arr[ei])
                {
                    rightcount++;
                    ei--;
                }
                if(leftele==arr[ei]) //if(arr[si]==arr[ei])
                {
                    int k=leftcount;
                    product=(k*(k-1))/2;

                }
                else
                {
                    product=leftcount*rightcount;
                }
                while(product--)
                {
                    cout<<arr[k]<<" "<<arr[si]<<" "<<arr[ei]<<endl;

                }
                si++;
                ei--;


            }
        }

	}
}

int main()
{
	int size;
	int x;
	cin>>size;
	int *input=new int[1+size];
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	FindTriplet(input,size,x);
	return 0;
}

