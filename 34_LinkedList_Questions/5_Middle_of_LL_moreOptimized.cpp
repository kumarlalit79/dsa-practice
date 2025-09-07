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

// Insert at tail
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Print Linked List
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimised middle finder (Tortoise–Hare Algorithm) - chatgpt version
Node* getMiddle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps
    }

    return slow; // slow will be at middle
}

// love babbar versiob
Node* getMiddle2(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    if (head -> next -> next == NULL)
    {
        
    }
    

    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }
        
        slow = slow->next;         
        
    }

    return slow; // slow will be at middle
}

int main() {
    // create first node
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    // insert more nodes
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    // insertAtTail(tail, 6);

    cout << "Linked List: ";
    print(head);

    // find middle
    Node* middle = getMiddle(head);
    cout << "Middle element is: " << middle->data << endl;

    return 0;
}
