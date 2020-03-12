//Best solution
//O(n)
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
Node *reverse_linked_list_rec(Node*head)
{
    if(head->next==NULL||head==NULL)
    {
        return head;
    }
    Node*sh=reverse_linked_list_rec(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
    return sh;

}




int main() {
    Node *head = takeinput();
    head = reverse_linked_list_rec(head);
    print(head);
    return 0;
}

