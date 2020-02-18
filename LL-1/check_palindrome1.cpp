//Check if a linked list is a palindrome
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
    if (head==NULL)
    {
        return 0;
    }
    return 1+length(head->next);
}
node*reverse_ll(node*h2)
{
    if(h2->next==NULL||h2==NULL)
        return h2;
    node*sh=reverse_ll(h2->next);
    node*tail=sh;
    while(tail->next!=NULL)
        tail=tail->next;
    tail->next=h2;
    h2->next=NULL;
    return sh;

}
bool check_palindrome(node*head)
{
    int len=length(head);
    int mid=0;
    if (len%2==0)
        mid=(len/2)-1;
    else
        mid=len/2;
    int i=0;
    node*h1=head,*temp=head;
    print(h1);
    while(i<mid)
    {
        temp=temp->next;
        i++;
    }
    node*h2=temp->next;
    h2=reverse_ll(h2);
    cout<<"\n";
    while(h2!=NULL)
    {
        if(h1->data==h2->data)
            {
            h1=h1->next;
            h2=h2->next;
            }
        else
            return false;

    }
    return true;
}


int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else
        cout << "false";
    return 0;
}
