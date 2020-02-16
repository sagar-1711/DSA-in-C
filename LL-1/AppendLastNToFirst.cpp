#include <iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

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

int length(node*temp)
{int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
 return i;
}
node* append_LinkedList(node* head,int n)
{
    //write your code here
    int i=0;
    node*h1=NULL;
    node*curr=NULL;
    node*tail=NULL;
    curr=head;
    int len=0;
    len=length(head);
    int count=len-n;
    while(i<count-1)
    {
        curr=curr->next;
        i++;
    }
    h1=curr->next;
    tail=h1;
    curr->next=NULL;
    while(tail->next!=NULL)
    {
        tail=tail->next;

    }
    tail->next=head;
    return h1;

}
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
