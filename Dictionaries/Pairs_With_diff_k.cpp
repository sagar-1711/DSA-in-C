#include <iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

void printPairsWithDifferenceK(int *input, int n, int k)
{
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        map[input[i]]+=1;
    }

    for(int i=0;i<n;i++)
    {
        int key=input[i];

        if(k==0)
    	{
            int freq=map[key];
            int count=freq*(freq-1)/2;
            for(int j=0;j<count;j++)
            {
                cout<<key<<" "<<key<<endl;
            }
    	}
        else
        {
            int freq=map[key];
            int a=key-k;
            int b=key+k;
            int freq1=map[a];
            int freq2=map[b];

            for(int j=0;j<freq*freq1;j++)
            {
                cout<<min(a,key)<<" "<<max(a,key)<<endl;

            }

            for(int j=0;j<freq*freq2;j++)
            {
                cout<<min(b,key)<<" "<<max(b,key)<<endl;
            }


        }
        map.erase(key);
    }

}




int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    printPairsWithDifferenceK(input, n, k);

    delete[] input;
}
