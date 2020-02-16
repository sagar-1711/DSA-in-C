
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
    if(i<0)
        return head;
    if(i==0)
    {
        Node*newNode = new Node(data);
        newNode->next=head;
        return newNode;
    }
    if(head==NULL)
    {
        return NULL;

    }
    Node*smallhead=insertati(head->next,i-1,data);
    head->next=smallhead;
    return head;
}

int main() {
    int i;
    int data;
    Node *head = takeinput();
    print(head);
    cout<<"enter position=";
    cin>>i;
    cout<<"\n enter data to be inserted=";
    cin>>data;
    head=insertati(head,i,data);
    print(head);
    return 0;
}

