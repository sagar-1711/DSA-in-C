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
void pairStar(char input[],int s)
{

    if(input[s]=='\0')
        return;

    pairStar(input,s+1);
    if(input[s]==input[s+1])
    {   int i;
        int length=len(input);
        input[length+1]='\0';
        for(i=length-1;i>=s+1;i--)
        {
            input[i+1]=input[i];
        }
        input[i+1]='*';
    }

}
void pairStar(char input[])
{
    pairStar(input,0);

}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

