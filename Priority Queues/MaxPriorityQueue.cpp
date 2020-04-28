#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue
{
    vector<int> pq;
public:
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMax()
    {
        if(isEmpty())
            return 0;
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int ci=pq.size()-1;
        while(ci!=0)
        {
            int pi=(ci-1)/2;
            if(pq[ci]>pq[pi])
            {
                //swap
                int temp=pq[ci];
                pq[ci]=pq[pi];
                pq[pi]=temp;
                ci=pi;
            }
            else
                break;
        }

    }
    int removeMax()
    {
        if(isEmpty())
            return -1;
        int ans=pq[0];
        pq[0]=pq.back();
        pq.pop_back();

        int pi=0;
        int lci=2*pi+1;
        int rci=lci+1;
        while(lci<pq.size())
        {
         	int mi=pi;
            if(pq[mi]<pq[lci])
                mi=lci;
            if(rci<pq.size() && pq[mi]<pq[rci])
                mi=rci;
            if(mi==pi)
                break;
            //swap pi & mi
            int temp=pq[pi];
            pq[pi]=pq[mi];
            pq[mi]=temp;
            pi=mi;
            lci=2*pi+1;
        	rci=lci+1;

        }

        return ans;
    }
};
int main()
{
    PriorityQueue p;
    p.insert(11);
    p.insert(4);
    p.insert(100);
    p.insert(45);
    p.insert(55);
    p.insert(2);
    while(!p.isEmpty())
    {
        cout<<p.removeMax()<<endl;

    }


}
