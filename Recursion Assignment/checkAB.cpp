#include <iostream>
using namespace std;


bool checkAB(char input[],int s)
{
    if(input[s]=='\0')
        return true;

    if(input[s]=='a')
    {
        if(input[s+1]=='b' && input[s+2]=='b')
            return checkAB(input,s+3);
        else
            return checkAB(input,s+1);
    }
    else
        return false;

}
bool checkAB(char input[])
{
	return checkAB(input,0);

}
int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
