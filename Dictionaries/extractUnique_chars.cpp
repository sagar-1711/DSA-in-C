#include<iostream>
using namespace std;
#include<unordered_map>
#include<cstring>
char* uniqueChar(char *str)
{
    int n=strlen(str);
    unordered_map<char,int> map;
    for(int i=0;i<n;i++)
    {
        map[str[i]]++;
    }
    char*output=new char[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        char z=str[i];
		if(map[z]>0)
        {
            output[j]=str[i];
            map[z]=0;
            j++;
        }

    }
    return output;

}
int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
