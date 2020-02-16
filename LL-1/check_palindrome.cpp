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
bool check_palindrome(node*head)
{
    int len=length(head);
    if (len==0 or len==1 or len%2!=0)
    {
        return false;
    }
    node*front=head,*rear=head;
    for(int i=1;i<len;i++)
    {
        rear=rear->next;

    }
    while(rear!=NULL)
    {
        if(front->data!=rear->data)
        {   return false;

        }
         front=front->next;
         rear=rear->next;
        return true;

    }
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
