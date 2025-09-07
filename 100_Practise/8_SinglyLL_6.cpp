#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtAnyPosition(Node* &head, Node* tail, int position,  int data){
    Node* temp = head;

    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    
    int count = 1;
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    if (head -> next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head , int position){
    
}

void print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    cout << node1 -> data << endl;

    insertAtHead(head, 9);
    print(head);

    insertAtHead(head, 8);
    print(head);

    insertAtTail(tail, 11);
    print(head);

    insertAtAnyPosition(head, tail, 4, 133);
    print(head);

    insertAtAnyPosition(head, tail, 1, 100);
    print(head);

    insertAtAnyPosition(head, tail, 7, 333);
    print(head);

    return 0;
}