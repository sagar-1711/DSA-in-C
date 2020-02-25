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
void removeX(char input[],int start,char x)
{
    if(start==length(input))
        return;
    removeX(input,start+1,x);
    if(input[start]==x)
    {   int i;
        for(i=start;i<=length(input);i++)
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
    removeX(input,0,'x');
    cout << input << endl;
}
