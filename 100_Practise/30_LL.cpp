#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int lengthLL(Node* &head){
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtTail(Node* &tail , int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,13);
    print(head);

    insertAtTail(tail,14);
    print(head);

    insertAtTail(tail,15);
    print(head);


    return 0;
}