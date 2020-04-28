#include <iostream>
using namespace std;
bool checkMaxHeap(int arr[], int n)
{
    int i=0;
    int lci=2*i+1;
    while(lci<n)
    {
        lci=2*i+1;
        int rci=2*i+2;
        if(arr[i]<arr[lci] && arr[i]<arr[rci])
            return false;
        i++;
    }
    return true;
}


int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    delete [] arr;
}
