#include<iostream>
using namespace std;
void tower_of_hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<"move 1st disc from "<<a<<" to "<<c<<"\n";
        return;
    }
    tower_of_hanoi(n-1,a,c,b);
    cout<<"move "<<n<<" th disc from "<<a<<" to "<<c<<"\n";
    tower_of_hanoi(n-1,b,a,c);
    return;

}
int main()
{   int n;
    cout<<"\nenter value of n = ";
    cin>>n;
    tower_of_hanoi(2,'a','b','c');
    return 0;
}
