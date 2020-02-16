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
Node* deleteNode(Node *head, int i) {

    Node*temp=head;

    if (i==0)
    {
        head=temp->next;
        temp->next=NULL;
        delete(temp);
        return head;
    }
    for(int j=0;j<i-1;j++)
    {

        temp=temp->next;
    }
    if(temp->next==NULL)
    {return head;
    }
    Node*temp1=temp;
    temp1=temp->next;
    temp->next=temp1->next;
    delete(temp1);
    return head;

}



int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}

