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

void insertAtAnyPosition(Node* &head, Node* &tail , int position, int data){

    Node* temp = head;

    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    
    int count = 1;
    while (count < position -1)
    {
        temp = temp -> next;
        count++;
    }

    if (temp -> next == NULL)
    {
        insertAtTail(tail, data);
        return ;
    }
    
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

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

void deleteNode(int position , Node* &head){
    
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;

        
    }
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    cout << node1 -> data << endl;

    insertAtHead(head, 9);
    print(head);

    insertAtTail(tail, 11);
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtAnyPosition(head, tail, 2,100 );
    print(head);

    insertAtAnyPosition(head, tail, 3,101 );
    print(head);

    insertAtAnyPosition(head, tail, 4,104 );
    print(head);

    insertAtAnyPosition(head, tail, 1,111 );
    print(head);

    insertAtAnyPosition(head, tail, 9,111 );
    print(head);

    return 0;
}