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
void deleteNode(int position, Node* &head){

    if(position == 1){
        // deleting 1st node
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL; // mai jisko bhi delete kar ra hoon, usko delete krne se pehle wo jisko bhi point kar ra usko mai hata doon. yaha temp ko delete kr ra tha to usko null point kara
        delete temp; // m/m free - check destructor above
    }
    else{
        // deleting middle and last node
        Node* curr = head; // pointer bana re
        Node* prev = NULL; // pointer bana re

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;

        curr -> next = NULL; //mai jisko bhi delete kar ra hoon, usko delete krne se pehle wo jisko bhi point kar ra usko mai hata doon. yaha curr ke next ko null point kar diya
        delete curr; // m/m free
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
    deleteNode(1, head);
    print(head);

    cout << endl;
    cout << "Deleting middle: " << endl;
    deleteNode(3, head);
    print(head);

    cout << endl;
    cout << "Deleting end: " << endl;
    deleteNode(5, head);
    print(head);


    return 0;
}