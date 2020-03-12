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
node* bubble_sort_LinkedList_itr(node* head)
{

    for(int i=0;i<length(head);i++)
    {
         node*prev=NULL,*curr=head;
         while(curr->next!=NULL)
         {
             if(curr->data>curr->next->data)
             {

                 if(prev!=NULL)
                 {
                    node*n=curr->next;
                    prev->next=curr->next;
                    curr->next=n->next;
                    n->next=curr;
                    prev=n;
                 }
                 else
                 {
                     node*n=curr->next;
                     curr->next=n->next;
                     n->next=curr;
                     prev=n;
                     head=prev;

                 }
             }
             else
             {
                 prev=curr;
                 curr=curr->next;
             }
        }


    }
    return head;
}

int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
