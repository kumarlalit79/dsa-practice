#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int _data){
        this -> data = _data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){ 
        cout << temp -> data << " "; 
        temp = temp -> next; 
    }
    cout << endl;
}

// finding LL length
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){ 
        len++;  
        temp = temp -> next; 
    }
    return len;
}

// insert at head
void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data); // new node create krdi usme data daal diya
    temp -> next = head; // temp ke next ko head mai daal diya
    head -> prev = temp; // head ke prev ko temp mai daal diya
    head = temp; // ab head ko new node pe point karwa diya
};


int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    print(head);

    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    print(head);

    cout << endl;
    cout << "Length of LL = " << getLength(head) << endl;
    return 0;
}