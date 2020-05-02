#include <iostream>
using namespace std;
int DuplicateNumber(int arr[], int n)
{
    int sum=0;
	for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int k=n-2;
    int s=(k*(k+1))/2;
    int ans=sum-s;
    return ans;
}
int main()
{
	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];
    cout << DuplicateNumber(input, size);
    delete [] input;
    return 0;
}
