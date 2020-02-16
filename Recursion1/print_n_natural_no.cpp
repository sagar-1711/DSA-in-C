#include<iostream>
using namespace std;
void print_natural(int n)
{   if(n==0)
        return;
    print_natural(n-1);
    cout<< n<<" ";
    return;
}
int main()
{   int n;
    cout<<"Enter value of n=";
    cin>>n;
    print_natural(n);

    return 0;

}
