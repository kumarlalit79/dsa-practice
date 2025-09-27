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

void insertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
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

void reverseLinkedList(Node* &head){
    
    if (head == NULL || head -> next == NULL)
    {
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while (curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail , 11);
    
    insertAtTail(tail , 12);
    
    insertAtTail(tail , 13);
    
    insertAtTail(tail , 14);
    
    insertAtTail(tail , 15);
    
    insertAtTail(tail , 16);

    cout << "Original LL" << endl;
    print(head);
    
    cout << "Reversed LL" << endl;
    reverseLinkedList(head);
    print(head);

}