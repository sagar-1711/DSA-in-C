//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include<iostream>
class node
{
public:
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* takeinput()
{
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
node* arrange_LinkedList(node* head)
{   node*temp=head;
    node*oh=NULL;
    node*ot=NULL;
    node*eh=NULL;
    node*et=NULL;
    while(temp!=NULL)
    {
        int value=temp->data;
        if(value%2==0)
        {
            if(et==NULL)
            {
                eh=temp;
                et=temp;

            }
            else
            {
              et->next=temp;
              et=et->next;
            }


        }
        else
        {
            if(ot==NULL)
            {
                oh=temp;
                ot=temp;

            }
            else
            {
              ot->next=temp;
              ot=ot->next;
            }


        }
        temp=temp->next;
    }
    if(ot==NULL)
        return head;
    if(et==NULL)
        return head;
    ot->next=eh;
    et->next=NULL;
    return oh;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
