#include<iostream>
using namespace std;
int power(int x,int n)
{   if(n==0)
        return 1;
    if(n==1)
        return x;
    return x*power(x,n-1);
}
int main()
{   int x,n;
    cout<<"\n Enter value of x=";
    cin>>x;
    cout<<"\n Enter value of n=";
    cin>>n;
    int p=power(x,n);
    cout<<"x^n="<<p;
    return 0;

}
