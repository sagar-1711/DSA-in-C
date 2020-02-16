
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
Node*deleteati(Node*head,int i)
{   if(head==NULL)
        return head;
    if(i==0)
    {
        Node*temp=head->next;
        delete(head);
        return temp;

    }
    Node*sh=deleteati(head->next,i-1);
    head->next=sh;
    return head;

}

int main() {
    int i;
    int data;
    Node *head = takeinput();
    print(head);
    cout<<"enter position=";
    cin>>i;
    head=deleteati(head,i);
    print(head);
    return 0;
}

