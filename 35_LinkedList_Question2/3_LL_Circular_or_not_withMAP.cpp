#include<iostream>
#include<map>
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

bool isCircularList(Node* head) {
    // case 1: empty list
    if (head == NULL) return false;

    map<Node*, bool> visited; // store visited nodes

    Node* temp = head;
    while (temp != NULL) {
        // agar node already visited hai → circular
        if (visited[temp] == true) {
            return true;
        }
        // mark visited
        visited[temp] = true;
        temp = temp->next;
    }

    return false; // NULL tak pahunch gaye → not circular
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
    // create list: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);

    cout << "Original List: ";
    print(head);

    if (isCircularList(head)) {
        cout << "Linked List is Circular\n";
    } else {
        cout << "Linked List is NOT Circular\n";
    }

    // Make it circular for testing
    tail->next = head;

    if (isCircularList(head)) {
        cout << "Linked List is Circular\n";
    } else {
        cout << "Linked List is NOT Circular\n";
    }

    return 0;
}
