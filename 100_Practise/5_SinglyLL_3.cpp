#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
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

void insertAtAnyPosition(Node* &head, int position, int data){
    Node* temp = head;
    int count = 1;
    while (count < position - 1 )
    {
        temp = temp -> next;
        count ++;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert; 
}

void print(Node* head){
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

    insertAtHead(head , 9);
    print(head);
    insertAtHead(head , 8);
    print(head);
    insertAtHead(head , 7);
    print(head);

    cout << "Tail insertion... "  << endl;

    insertAtTail(tail , 11);
    print(head);
    insertAtTail(tail , 12);
    print(head);
    insertAtTail(tail , 13);
    print(head);

    cout << "Any Position insertion... "  << endl;

    insertAtAnyPosition(head, 3, 18);
    print(head);
    insertAtAnyPosition(head, 4, 19);
    print(head);


    return 0;
}