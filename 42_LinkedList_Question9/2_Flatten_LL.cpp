#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;   // ye vertically "down" pointer ka kaam karega
    Node* right;  // ye horizontally agle list ka pointer hai

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->right = NULL;
    }
};

// Utility function to insert at end of vertical list
void insertDown(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two sorted linked lists (downwards)
Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    result->right = NULL; // right pointer ko null karte rahenge
    return result;
}

// Function to flatten the linked list
Node* flatten(Node* head) {
    // base case
    if (head == NULL || head->right == NULL) {
        return head;
    }

    // Step 1: Right list ko flatten karo
    Node* rightFlattened = flatten(head->right);

    // Step 2: Apni current list ko rightFlattened ke saath merge karo
    Node* ans = merge(head, rightFlattened);

    return ans;
}

// Utility function to print vertical linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example setup (4 vertical linked lists)
    Node* head = new Node(5);
    insertDown(head, 7);
    insertDown(head, 8);
    insertDown(head, 30);

    head->right = new Node(10);
    insertDown(head->right, 20);

    head->right->right = new Node(19);
    insertDown(head->right->right, 22);
    insertDown(head->right->right, 50);

    head->right->right->right = new Node(28);
    insertDown(head->right->right->right, 35);
    insertDown(head->right->right->right, 40);
    insertDown(head->right->right->right, 45);

    cout << "Flattened Linked List: ";
    Node* result = flatten(head);
    printList(result);

    return 0;
}
