#include<iostream>
#include<algorithm>
using namespace std;
void pairSum(int arr[], int size, int x)
{
    sort(arr,arr+size);
    int si=0;
    int ei=size-1;
    while(si<ei)
    {
        if(arr[si]+arr[ei]<x)
        	si++;
    	else if(arr[si]+arr[ei]>x)
        	ei--;
        else //if(arr[si]+arr[ei]==x)
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
                cout<<arr[si]<<" "<<arr[ei]<<endl;

            }
            si++;
            ei--;


   	 	}


    }

}

int main() {

	int size;
	int x;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	pairSum(input,size,x);

	return 0;
}
