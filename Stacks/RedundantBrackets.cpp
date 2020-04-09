#include <iostream>
using namespace std;
#include<stack>
#include<cstring>
bool checkRedundantBrackets(char *input)
{
    int count;
    char top;
    stack<char> s;
    int n=strlen(input);
    for(int i=0;i<n;i++)
    {
        char ch=input[i];
        if(ch!=')')     //ch=='('||ch==(any char or operators =,-,/,*)
            s.push(ch);
        else   //if ch==')'
        {
            if(s.top()=='(')
                return true;
            //if top element of stack does not contain op
            while(s.top()!='(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;

}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
