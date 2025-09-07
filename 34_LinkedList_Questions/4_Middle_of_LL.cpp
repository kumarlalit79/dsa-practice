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

int getLength(Node* head){

    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head -> next;
    }
    return length;

}

Node* getMiddle(Node* head) {
    int len = getLength(head);
    int mid = (len / 2); // 0-based index

    Node* temp = head;
    int count = 0;

    while (count < mid) {
        temp = temp->next;
        count++;
    }

    return temp;
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
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    // insert more nodes
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);

    cout << "Linked List: ";
    print(head);

    Node* middle = getMiddle(head);
    cout << "Middle Node Value = " << middle->data << endl;


    return 0;
}
