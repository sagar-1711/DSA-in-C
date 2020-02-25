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
void replace_pi(char input[],int start)
{
    if(start==length(input))
        return;
    replace_pi(input,start+1);
    if(input[start]=='p' && input[start+1]=='i')
    {   for(int i=length(input)+2;i>=start+2;i--)
        {
            input[i+2]=input[i];
        }
        input[start]='3';
        input[start+1]='.';
        input[start+2]='1';
        input[start+3]='4';
    }
    else
        return;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    replace_pi(input,0);
    cout << input << endl;
}
