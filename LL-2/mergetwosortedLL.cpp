#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
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
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
Node* mergeTwoLLs(Node *h1, Node *h2)
{
    Node*head,*tail;
    if(h1->data<h2->data)
    {
        head=h1;
        tail=h1;
        h1=h1->next;
    }
    else
    {
         head=h2;
         tail=h2;
         h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<h2->data)
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;

        }
        else
        {

           tail->next=h2;
           tail=h2;
           h2=h2->next;
        }
    }
    if(h1!=NULL)
    {
        tail->next=h1;
    }
    if(h2!=NULL)
    {
        tail->next=h2;
    }
return head;

}
int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

