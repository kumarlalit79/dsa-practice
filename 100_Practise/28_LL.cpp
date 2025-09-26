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

    ~Node(){
        int value = this->data;
        if (this -> next !=NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for : " << value << endl;
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

void deleteLL(Node* head, int position){

    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;

        delete temp;
    }
    else{

        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

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

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);
    insertAtTail(tail,16);
    print(head);

    int position;
    cout << "Enter position" << endl;
    cin >> position;

    //insertAtPosition(head, tail, position , 9);
    //print(head);

    deleteLL(head, position);
    print(head);
    
    return 0;
}