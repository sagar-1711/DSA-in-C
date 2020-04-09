#include <iostream>
#include<stack>
using namespace std;
int* stockSpan(int *price, int size)
{
    stack<int> s;
	int*span=new int[size];
    span[0]=1;
    s.push(0);

    for(int i=1;i<size;i++)
    {
        while(!s.empty() && price[i]>price[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            span[i]=i+1;
        }
        else
        {
            span[i]=i-s.top();
        }
        s.push(i);
     }
    return span;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

