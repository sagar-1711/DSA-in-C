#include <iostream>
#include<vector>
using namespace std;
void down_heapify(int*arr,int i,int n)
{
    int pi=i;
    int lci=2*pi+1;
    int rci=2*pi+2;
    while(lci<n)
    {
        int mi=pi;
        if(arr[mi]>arr[lci])
            mi=lci;
        if(rci<n && arr[mi]>arr[rci])
            mi=rci;
        if(mi==pi)
            break;
        //swap
        int temp=arr[pi];
        arr[pi]=arr[mi];
        arr[mi]=temp;
        pi=mi;
        lci=2*pi+1;
        rci=2*pi+2;
    }
    return;

}
void inplaceHeapSort(int*arr,int n)
{
    //Build Heap by moving upwards so that heap is maintained below that.Start from non leaf node
    for(int i=(n/2)-1;i>=0;i--)
    {
        down_heapify(arr,i,n);
    }
    //Perform removemin operation
    for(int i=n-1;i>0;i--)
    {
        //performremove minimum and put it at last
        //swap first and last values
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        //now heap is disturbed  so perform downheapify to make heap till ith index
        down_heapify(arr,0,i);
    }
    return;
}

int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";

	return 0;
}
