#include<iostream>
using namespace std;


class Node{

    public :
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head , int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
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
    cout << node1 -> data << endl;

    insertAtHead(head , 11);
    print(head);
    insertAtHead(head , 12);
    print(head);
    insertAtHead(head , 13);
    print(head);
    insertAtHead(head , 14);
    print(head);

    return 0;
}