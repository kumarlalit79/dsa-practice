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

    // Destructor
    ~Node(){
        int val = this -> data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
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
void insertAtHead(Node* &tail, Node* &head, int data){

    if(head == NULL){
        Node* temp = new Node(data); 
        head = temp; 
        tail = temp; 
    }
    else{
        Node* temp = new Node(data); 
        temp -> next = head; 
        head -> prev = temp; 
        head = temp; 
    }
};

// insert at tail
void insertATail(Node* &tail, Node* &head, int data){

    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp; 
        head = temp; 
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node* &head, Node* &tail, int position, int data){
    
    Node* temp = head;  
    if (position == 1)
    {
        insertAtHead(tail,head, data);
        return;
    }
    
    int count = 1;
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    if (temp -> next == NULL)
    {
        insertATail(tail, head, data);
        return;
    }
    
    Node* nodeToInsert = new Node(data); 
    nodeToInsert -> next = temp->next; 
    temp -> next -> prev = nodeToInsert; 
    temp -> next = nodeToInsert; 
    nodeToInsert -> prev = temp;  
    
}

// deletion
void deleteNode(int position, Node* &head){

    if(position == 1){
        // deleting 1st node
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
       
        Node* curr = head; 
        Node* prev = NULL; 

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL; 
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr; 
    }
}


int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    print(head);

    // inserting at head
    insertAtHead(tail, head, 11);
    insertAtHead(tail, head, 12);
    insertAtHead(tail, head, 13);
    print(head);

    // inserting at end
    insertATail(tail, head, 14);
    print(head);

    // inserting at any position
    insertAtAnyPosition(head, tail, 3, 100); // inserting middle
    insertAtAnyPosition(head, tail, 1, 101); // inserting 1st position
    insertAtAnyPosition(head, tail, 8, 501); // inserting end position
    print(head);

    cout << endl;    

    // deleting node
    deleteNode(1, head); // 1st node ko delete kar re
    deleteNode(7, head); // 1st node ko delete kar re
    deleteNode(3, head); // 1st node ko delete kar re
    print(head);



    cout << endl;
    cout << "Length of LL = " << getLength(head) << endl;
    return 0;
}