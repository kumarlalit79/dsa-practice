#include<iostream>
using namespace std;

class Node{

    public : 
    int data;
    Node *next;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head , int data){

    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    Node* temp = tail;
    int count = 1;
    if (position == 1)
    {
        insertAtHead(head , data);
    }
    
    
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

    if (temp -> next == NULL)
    {
        insertAtTail(tail, data);
    }
    

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

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,13);
    print(head);

    int position = 1;

    insertAtPosition(head, tail, position , 9);
    print(head);

    cout << "Length : " << lengthLL(head);

    return 0;
}