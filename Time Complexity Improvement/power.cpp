#include<iostream>
using namespace std;
//TC=O(logn)
//SC=O(logn)
int power(int x, int n)
{
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    int smallpower=power(x,n/2);
    if(n%2==0)
        return smallpower*smallpower;
    else
        return smallpower*smallpower*x;
}

int main(){
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
}
