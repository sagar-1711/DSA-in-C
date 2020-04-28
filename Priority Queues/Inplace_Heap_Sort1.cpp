#include <iostream>
#include<vector>
using namespace std;
void inplaceHeapSort(int*input,int n)
{
    //Build Heap inside array
    for(int i=1;i<n;i++)
    {
        int ci=i;
        int pi;
        while(ci!=0)
        {
            pi=(ci-1)/2;
            if(input[ci]<input[pi])
            {
                //swap
                int temp=input[ci];
                input[ci]=input[pi];
                input[pi]=temp;
                ci=pi;
            }
            else
                break;
        }
    }
    //Perform removemin operation
    int size=n;
    while(size>1)
    {
        //swap input[0] & input[i]
        int temp=input[size-1];
        input[size-1]=input[0];
        input[0]=temp;
        size--;
        int pi=0;
        int lci=2*pi+1;
        int rci=2*pi+2;
        while(lci<size)
        {
            int mi=pi;
            if(input[mi]>input[lci])
                mi=lci;
            if(rci<size && input[mi]>input[rci])
                mi=rci;
            if(mi==pi)
                break;
            int temp=input[pi];
            input[pi]=input[mi];
            input[mi]=temp;
            pi=mi;
            lci=2*pi+1;
            rci=2*pi+2;
        }
    }

}


int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
    return 0;
}
