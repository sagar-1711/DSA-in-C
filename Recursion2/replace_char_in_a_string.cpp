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
void replace_a(char input[],char a,char b)
{
    if(length(input)==0)
        return;
    replace_a(input+1,a,b);
    if(input[0]==a)
    {
        input[0]=b;
    }
    else
        return;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    replace_a(input,'a','b');
    cout << input << endl;
}
