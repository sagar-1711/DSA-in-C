#include <iostream>
using namespace std;
int sumOfDigits(int n) {
    // Write your code here
    if(n==0)
        return 0;
    int digit=n%10;
    return digit+sumOfDigits(n/10);

}

int main()
{
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
