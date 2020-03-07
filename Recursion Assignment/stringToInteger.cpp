#include <iostream>
using namespace std;
int len(char input[])
{   int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    }
 return count;

}
int stringToNumber(char input[],int e)
{
    if(e==0)
    {
        int b=input[0]-'0';
        return b;
    }
    int b=input[e]-'0';
    int a=stringToNumber(input,e-1);
    return (a*10)+b;
}
int stringToNumber(char input[])
{
    int ans=stringToNumber(input,len(input)-1);
    return ans;

}
int main()
{
    char input[50];
    cin >> input;
    cout <<stringToNumber(input)<<endl;
}
