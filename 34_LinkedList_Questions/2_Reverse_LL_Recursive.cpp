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

void reverseLinkedList(Node* &head, Node* curr, Node* prev) {
    // base case
    if (curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverseLinkedList(head, forward, curr);
    curr->next = prev;
}

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

int main() {
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

    // call recursion reverse
    reverseLinkedList(head, head, NULL);

    cout << "Reversed List: ";
    print(head);

    return 0;
}
