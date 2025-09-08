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

bool isCircularList(Node* head){

    // case 1 : empty list
    if (head == NULL)
    {
        return true;
    }
    
    // case 2 and case 3 overlap kr re, to un dono ke liye ek hi case banega
    Node* temp = head -> next; // ek node bana li

    // Traverse until either NULL or head is reached again
    while (temp != NULL && temp != head)
    {
        temp = temp -> next;
    }
    
    // If we stopped because temp == head → circular
    if (temp == head)
    {
        return true;
    }
    
    return false;

}

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return ;
    }
    

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    
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

    // Test circular check
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
