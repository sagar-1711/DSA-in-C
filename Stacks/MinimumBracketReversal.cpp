#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
int countBracketReversals(char input[])
{
 	if(strlen(input)%2!=0)
        return -1;
    stack<int> s;
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]=='{')
            s.push(input[i]);
        else//if(x=='}')
        {
            if(s.empty())
                s.push(input[i]);
            else if(!s.empty())
            {
                if(s.top()=='{')
                    s.pop();
                else if(s.top()=='}')
                    s.push(input[i]);
            }
        }
    }
    //now we are left with stack with unbalanced brackets
    int count=0;
    while(!s.empty())
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        if(c1==c2)
        {
            count+=1;
        }
        else
        {
            count+=2;
        }
    }
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
