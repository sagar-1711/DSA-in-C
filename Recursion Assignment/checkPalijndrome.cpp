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
bool helper(char input[],int s,int e)
{
    if(s>=e)
        return true;

    if(input[s]!=input[e])
        return false;
    return helper(input,s+1,e-1);

}

bool checkPalindrome(char input[])
{
    // Write your code here
    return helper(input,0,length(input)-1);
}



int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
