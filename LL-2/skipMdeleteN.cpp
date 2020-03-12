//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* skipMdeleteN(node*head, int M, int N)
{

    if(M==0)
        return NULL;
    int c1,c2;
    node*t1=head;
    node*t2=head;
    while(t2)
    {   c1=1;
        c2=1;
        while(c1<M && t1!=NULL)
        {
            t1=t1->next;
            c1++;

        }
        if(t1==NULL)
            return head;
        t2=t1->next;
        while(c2<=N && t2!=NULL)
        {   node*temp=t2;
            t2=t2->next;
            delete(temp);
            c2++;

        }
        t1->next=t2;
        t1=t2;


    }
    return head;


}



int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m>>n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}

