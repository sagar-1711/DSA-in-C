//merge sort on linked list ,making recursive merge function
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
        if(head==NULL)
         {
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
    if (head==NULL)
    {
        return 0;
    }
    return 1+length(head->next);
}
node*find_mid(node*head)
{
    node*slow,*fast;
    slow=head;
    fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;

    }
    return slow;
}
node*merge_LL(node*LL1,node*LL2)
{   node*finalhead=NULL;
    if(LL1==NULL)
        return LL2;
    if(LL2==NULL)
        return LL1;
    if(LL1->data<LL2->data)
    {    finalhead=LL1;
         finalhead->next=merge_LL(LL1->next,LL2);
    }
    else
    {
         finalhead=LL2;
         finalhead->next=merge_LL(LL1,LL2->next);
    }
    return finalhead;

}
node*merge_sort(node*head)
{   if(head==NULL or head->next==NULL)
        return head;
    node*mid=find_mid(head);
    node*LL1=head;
    node*LL2=mid->next;
    mid->next=NULL;
    LL1=merge_sort(LL1);
    LL2=merge_sort(LL2);
    node*finalhead=merge_LL(LL1,LL2);
    return finalhead;
}

int main()
{
    node*head=takeinput();
    node*fh=merge_sort(head);
    cout<<"sorted LL"<<endl;
    print(fh);
    return 0;
}
