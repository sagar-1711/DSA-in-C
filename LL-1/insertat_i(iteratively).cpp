#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}
int length(Node *head) {
    if (head==NULL)
        return 0;
    return 1+length(head->next);
}
Node*insertati(Node*head,int i,int data)
{
    if (i<0 || i>length(head))
    {
        return head;
    }
    Node*prev=NULL,*curr=head;
    int count=0;
    while (count<i)
    {
        prev=curr;
        curr=curr->next;
        count++;
    }
    Node*newNode=new Node(data);
    if (prev!=NULL)
    {
        prev->next=newNode;

    }
    else
    {
        head=newNode;

    }
    newNode->next=curr;
    return head;

}

int main() {
    int i;
    int data;
    Node *head = takeinput();
    print(head);
    cout<<"enter position=";
    cin>>i;
    cout<<"\nenter data to be inserted=";
    cin>>data;
    head=insertati(head,i,data);
    print(head);
    return 0;
}

