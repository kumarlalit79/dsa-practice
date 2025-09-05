#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    // destructor for memory free
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
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

void insertAtAnyPosition(Node* &head , Node* &tail,  int position , int data){ 
    Node* temp = head;    
    
    if(position == 1){
        insertAtHead(head, data);
        return ;
    }

    int count = 1;
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    if (temp -> next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp->next;
    temp -> next = nodeToInsert;
}    


// Deletion through position
void deleteNode(int position, Node* &head, Node* &tail) {
    if(position == 1) {
        // deleting 1st node
        Node* temp = head;
        head = head -> next;

        // agar ek hi node thi
        if(head == NULL) {
            tail = NULL;
        }

        temp -> next = NULL; 
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        // agar delete karne wala node last node hai
        if(curr -> next == NULL) {
            tail = prev;          // tail ko update karo
            prev -> next = NULL;  // new tail ka next null hoga
        } 
        else {
            prev -> next = curr -> next;
        }

        curr -> next = NULL;
        delete curr;
    }
}


void print(Node* &head){
    Node* temp =  head;

    while (temp != NULL)
    {
        cout << temp -> data << " "; 
        temp = temp -> next; 
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(100);

    Node* head = node1;   
    Node* tail = node1;  

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 17);
    insertAtTail(tail, 19);
    print(head);
    
    insertAtAnyPosition(head, tail, 1, 222);
    insertAtAnyPosition(head, tail, 7, 555);
    print(head);

    cout << endl;
    cout << "Deleting 1st: " << endl;
    deleteNode(1, head, tail);
    print(head);

    cout << endl;
    cout << "Deleting middle: " << endl;
    deleteNode(3, head, tail);
    print(head);

    cout << endl;
    cout << "Deleting end: " << endl;
    deleteNode(5, head, tail);
    print(head);


    return 0;
}