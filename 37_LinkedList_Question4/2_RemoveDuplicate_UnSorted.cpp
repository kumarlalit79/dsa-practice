#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* removeDuplicatesUnsorted(Node* head) {
    if (head == NULL)
        return NULL;

    unordered_map<int, bool> visited; // track seen elements

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (visited[curr->data] == true) {
            // Duplicate found -> delete node
            prev->next = curr->next;
            Node* nodeToDelete = curr;
            curr = curr->next;
            delete nodeToDelete;
        }
        else {
            visited[curr->data] = true; // mark as seen
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    // Example: Unsorted list with duplicates
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 40);
    insertAtTail(tail, 20);
    insertAtTail(tail, 10); // duplicate
    insertAtTail(tail, 30);
    insertAtTail(tail, 20); // duplicate
    insertAtTail(tail, 50);
    insertAtTail(tail, 40); // duplicate
    insertAtTail(tail, 60);

    cout << "Original Unsorted List (with duplicates): ";
    print(head);

    head = removeDuplicatesUnsorted(head);

    cout << "After Removing Duplicates: ";
    print(head);

    return 0;
}
