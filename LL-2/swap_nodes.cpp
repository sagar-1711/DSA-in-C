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
node* swap_nodes(node *head,int i,int j)
{
    //if i>j swap i & j
    if(i>j)
    {
        int temp=i;
        i=j;
        j=temp;
    }
    node*temp=head,*prev=NULL;
    node*p1=NULL,*c1=NULL,*p2=NULL,*c2=NULL;
    int count=0;
    while(temp!=NULL)
    {
        if(i==count)
        {
            p1=prev;
            c1=temp;


        }
        if(j==count)
        {
            p2=prev;
            c2=temp;
        }
        count++;
        prev=temp;
        temp=temp->next;

    }
    if(c1==NULL || c2==NULL)
        return head;

  temp=c2->next;
   if(i==0 && j-i==1)
//if alternate nodes are there an one is head;
   {
       head=c2;
       c1->next=c2->next;
       c2->next=c1;

   }
   //if one is head
   else if(i==0)
   {
       head=c2;
       c2->next=c1->next;
       p2->next=c1;
       c1->next=temp;

   }
    //if alternate nodes are there
    else if(j-i==1)
    {
       p1->next=c2;
        c1->next=c2->next;
        c2->next=c1;
    }
    //if none of the nodes is head and no alternate nodes
    else
    {
       p1->next=c2;
       c2->next=c1->next;
       p2->next=c1;
       c1->next=temp;
    }

    return head;

}


int main()
{   int i,j;
    cout<<"\n enter i=";
    cin>>i;
    cout<<"\n enter j=";
    cin>>j;

    node* head=takeinput();
    head=swap_nodes(head,i,j);
    print(head);
}
