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
int indexOfNRecursive(Node*head,int x)
{
    if (head==NULL)
        return -1;
    if(head->data==x)
        return 0;
    int i=indexOfNRecursive(head->next,x);
    if (i==-1)
        return -1;
    else
        return i+1;
}

int main() {
    Node *head = takeinput();
    int x;
    cin >>x;
    cout << indexOfNRecursive(head,x);

}

