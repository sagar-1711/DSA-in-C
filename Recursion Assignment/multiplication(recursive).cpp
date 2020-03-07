#include <iostream>
using namespace std;
int multiplyNumbers(int m, int n)

{

    if(n==0)
        return 0;
    return multiplyNumbers(m,n-1)+m;


}



int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
