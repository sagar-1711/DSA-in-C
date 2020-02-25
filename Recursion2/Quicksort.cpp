#include<iostream>
using namespace std;
int partition_(int input[],int si,int ei)
{
    int pivot=input[si];
    int c=0;
    for(int i=si;i<=ei;i++)
    {
        if(input[i]<pivot)
            c++;
    }
    //move pivot at correct position
    int pivot_index=si+c;
    int temp=input[si+c];
    input[si+c]=input[si];
    input[si]=temp;
    int i=si;
    int j=ei;
    while(i<pivot_index && j>pivot_index)
    {
        if(input[i]<pivot)
            i++;
        else if(input[j]>pivot)
            j--;
        else
        {
            int t=input[i];
            input[i]=input[j];
            input[j]=t;
            i++;
            j--;
        }
    }
    return pivot_index;
}
void quickSort(int input[],int si,int ei)
{
    if(si>ei)
        return;
    int c=partition_(input,si,ei);
    quickSort(input,si,c-1);
    quickSort(input,c+1,ei);

}

int main()
 {
  int input[1000],length;
  cout<<"enter length"<<endl;
  cin >> length;
  cout<<"enter input unsorted array"<<endl;
  for(int i=0; i < length; i++)
  {
      cin >> input[i];
  }
  quickSort(input,0,length-1);
  cout<<"\n sorted array"<<endl;
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  return 0;
}
