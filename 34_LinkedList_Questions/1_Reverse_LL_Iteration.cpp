#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void reverseLinkedlist(Node* &head){
    if (head == NULL || head -> next == NULL)
    {
        return; 
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;   // Save next node
        curr->next = prev;      // Reverse the link
        prev = curr;            // Move prev forward
        curr = forward;         // Move curr forward
    }
    head = prev; // // direct update, New head
}

// insert at tail helper
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    // create first node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // insert more nodes
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);

    cout << "Original List: ";
    print(head);

    reverseLinkedlist(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}