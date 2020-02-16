//Eliminate duplicates from a sorted linked list
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
node* eliminate_duplicate(node* head)
{
    //write your code here
    node*t1=head;
    node*t2=head->next;
    if(head==NULL || head->next==NULL )
        return head;
   while(t2!=NULL)
    {
        if(t2->data==t1->data)
        {
         t2=t2->next;

        }
        else
        {   t1->next=t2;
            t1=t2;
            t2=t2->next;
        }
    }
    t1->next=t2;
    return head;
}

int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

