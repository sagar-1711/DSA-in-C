#include <iostream>
using namespace std;
// arr - input array
// n - size of array
int equilibrium(int arr[], int n)
{
    int ls=0;
	int rs=0;
    int ans=0;
	for(int i=1;i<n;i++)
    {
         rs+=arr[i];
    }
    for(int i=1;i<n;i++)
    {
        ls+=arr[i-1];
        rs-=arr[i];
        if(ls==rs)
        {
            ans=i;
            break;
        }

    }
    if(ans==0)
        return -1;
    else
    	return ans;

}

int main() {
	int size;
	cin >> size;
	int *input=new int[1 + size];

	for(int i = 0; i < size; i++){
		cin >> input[i];
    }
	cout << equilibrium(input, size);

	delete [] input;
	return 0;
}
