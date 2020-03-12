//O(n) by maintaining tail
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
        return head,head;
    }
    Node*sh,*st=reverse_linked_list_rec(head->next);
    st->next=head;
    head->next=NULL;
    return sh,head;

}




int main() {
    Node *head = takeinput();
    head= reverse_linked_list_rec(head);
    print(head);
    return 0;
}

