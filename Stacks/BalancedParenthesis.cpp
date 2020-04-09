#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool checkBalanced(char *exp)
{
    stack<char> s;
    int n=strlen(exp);
	for(int i=0;i<n;i++)
    {
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
        {
        	s.push(exp[i]);
        }
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
        {
            //if  expression has brackets left but stackis already empty eg; {}}
            if(s.empty())
                return false;
        	if((s.top()=='{' && exp[i]=='}')||(s.top()=='(' && exp[i]==')')||(s.top()=='[' && exp[i]==']'))
            {
                s.pop();
            }
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    return false;

}
int main()
{
    char input[10000];
    cin.getline(input,10000);
    if(checkBalanced(input))
        cout<<"true";
    else
        cout<<"false";
}
