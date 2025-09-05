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
void insertAtHead(Node* &tail, Node* &head, int data){

    if(head == NULL){
        Node* temp = new Node(data); // new node banai,ab ye hi new node hamari temp hai
        head = temp; // head ko yaha pe update kar diya
        tail = temp; // tail ko yaha pe update kar diya
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
        Node* temp = new Node(data); // new node banai,ab ye hi new node hamari temp hai
        tail = temp; // tail ko yaha pe update kar diya
        head = temp; // head ko yaha pe update kar diya
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

// insert any position
void insertAtAnyPosition(Node* &head, Node* &tail, int position, int data){
    
    Node* temp = head;  
    // agr start mai insert karna ho to
    if (position == 1)
    {
        insertAtHead(tail,head, data);
        return;
    }

    // Ye loop sirf temp ko correct node tak pahunchane ka kaam karta hai
    int count = 1;
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    // insert at last position
    if (temp -> next == NULL)
    {
        insertATail(tail, head, data);
        return;
    }
    
    // insert at middle position
    Node* nodeToInsert = new Node(data); // step 1
    nodeToInsert -> next = temp->next; // step 2
    temp -> next -> prev = nodeToInsert; // step 3
    temp -> next = nodeToInsert; // step 4
    nodeToInsert -> prev = temp; // step 5 
    
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
    cout << "Length of LL = " << getLength(head) << endl;
    return 0;
}