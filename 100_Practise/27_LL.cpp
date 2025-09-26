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

void insertAtTail(Node* &tail , int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &tail, int position, int data){

    Node* temp = tail;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
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

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,13);
    print(head);

    int position = 2;

    insertAtPosition(head, position , 9);
    print(head);

    return 0;
}