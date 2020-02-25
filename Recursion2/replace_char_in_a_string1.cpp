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
void replace_a(char input[],int start,char a,char b)
{
    if(start==length(input))
        return;
    replace_a(input,start+1,a,b);
    if(input[start]==a)
    {
        input[start]=b;
    }
    else
        return;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    replace_a(input,0,'a','b');
    cout << input << endl;
}
