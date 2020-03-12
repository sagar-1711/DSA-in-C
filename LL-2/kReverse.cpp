//bubble sort iterative
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
int length(node*head)
{
    if(head==NULL)
        return 0;
    return 1+length(head->next);
}
node* kReverse(node*head,int k)
{

    node*prev=NULL,*curr=head,*next=NULL;
    int count=0;
    while(curr!=NULL && k!=count)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
        head->next=kReverse(next,k);
    return prev;
}


int main()
{   int k;
    cout<<"\n enter k=";
    cin>>k;

    node* head=takeinput();
    head=kReverse(head,k);
    print(head);
}
