#include <iostream>
using namespace std;
int countZeros(int n)
{

    if(n<=9)
    {
        if(n==0)
            return 1;
        return 0;
    }
    int z=countZeros(n/10);
    int ld=n%10;
    if(ld==0)
        z+=1;
    return z;

}


int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
