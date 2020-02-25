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
void removeX(char input[],char x)
{
    if(length(input)==0)
        return;
    removeX(input+1,x);
    if(input[0]==x)
    {   int i;
        for(i=0;i<=length(input);i++)
        {
            input[i]=input[i+1];
        }
        input[i]='\0';
    }
    else
        return;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input,'x');
    cout << input << endl;
}
