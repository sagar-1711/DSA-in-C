//merge sort on linked list
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
{
    node*head1=LL1;
    node*head2=LL2;
    node*head=NULL;
    node*tail=NULL;
    while(head1!=NULL && head2!=NULL)
    {   if(head1->data<head2->data)
            {
                if(tail==NULL)
                {
                    head=head1;
                    tail=head1;
                    head1=head1->next;

                }
                else
                {
                    tail->next=head1;
                    tail=tail->next;
                    head1=head1->next;
                }

            }
        else
        {
            if(tail==NULL)
                {
                    head=head2;
                    tail=head2;
                    head2=head2->next;

                }
                else
                {
                    tail->next=head2;
                    tail=tail->next;
                    head2=head2->next;
                }
        }

    }
    if(head1!=NULL)
        tail->next=head1;
    if(head2!=NULL)
        tail->next=head2;
    return head;
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
