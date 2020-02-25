//remove consecutive duplicates recursively
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
void remove_duplicates(char input[])
{
    if(length(input)==0)
        return;
    remove_duplicates(input+1);
    if(input[0]==input[1])
    {
       int i;
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
    remove_duplicates(input);
    cout << input << endl;
}
