#include <iostream>
#include <math.h>
using namespace std;
double geometricSum(int k)
{
    if(k==0)
       return 1;
    float s=geometricSum(k-1);
    return s+1/pow(2,k);
}
int main()
{
    int k;
    cin >> k;
    cout << geometricSum(k) << endl;
}
