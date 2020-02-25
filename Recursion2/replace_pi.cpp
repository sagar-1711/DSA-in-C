#include <iostream>
using namespace std;
int length(char input[])
{
    int len=0;
    for(int i=0;input[i]!='\0';i++)
    {
        len++;
    }
    return len;
}
void replace_pi(char input[])
{
    if(length(input)==0 )
        return;
    replace_pi(input+1);
    if(input[0]=='p' && input[1]=='i')
    {   for(int i=length(input)+2;i>=2;i--)
        {
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    else
        return;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    replace_pi(input);
    cout << input << endl;
}
