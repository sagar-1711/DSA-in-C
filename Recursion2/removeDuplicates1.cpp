//remove consecutive duplicates recursively using start
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

void remove_duplicates(char input[],int start)
{
    if(start==length(input) || start==length(input)-1)
        return;
    remove_duplicates(input,start+1);
    if(input[start]==input[start+1])
    {
        int i;
        for(i=start;input[i]!='\0';i++)
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
    remove_duplicates(input,0);
    cout << input << endl;
}
