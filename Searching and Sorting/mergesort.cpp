#include<iostream>
using namespace std;
void merg(int a1[],int size1,int a2[],int size2,int output[])
{
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(a1[i]<a2[j])
        {
            output[k]=a1[i];
            k++;
            i++;
        }
        else
        {
            output[k]=a2[j];
            k++;
            j++;
        }
    }
    while(i<size1)
    {
        output[k]=a1[i];
        i++;
        k++;

    }
    while(j<size2)
    {
        output[k]=a2[j];
        j++;
        k++;

    }


}
void mergeSort(int input[],int length)
{
    if(length<=1)
       {
           return;
       }
    int mid=length/2;
    int size1=mid;
    int size2=length-mid;
    int part1[500];
    int part2[500];
    for(int i=0;i<mid;i++)
        {
        part1[i]=input[i];
        }
    int k=0;
    for(int i=mid;i<length;i++)
    {

        part2[k]=input[i];
        k++;
    }
    mergeSort(part1,size1);
    mergeSort(part2,size2);
    merg(part1,size1,part2,size2,input);

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
  mergeSort(input,length);
  cout<<"\n sorted array"<<endl;
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  return 0;
}
