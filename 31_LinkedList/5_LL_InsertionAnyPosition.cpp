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
};

// Insertion at tail
void insertAtTail(Node* &tail, int data){ 
        
    Node* temp = new Node(data);
    tail -> next = temp; // tail ke next ko temp node pe point karwa diya. link new node at the end
    tail = temp; // tail = tail -> next; ye bhi likh sakte. move tail to new node
} 

// Insertion at any position
void insertAtAnyPosition(Node* &head , int position , int data){ 
    Node* temp = head;    
    int count = 1;// starting mein to mai pehli node pe hi honga

    // ab like mujhe 3 pe jana hai to pehle 2 pe jana hoga, 5 pe jane ke liye 4 pe, to loop laga do
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    // ab is parameter data ke liye ek node bana do
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp->next;
    temp -> next = nodeToInsert;
}    

// printing / traversing LL
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

    Node* head = node1;   // head ko bhi store karna hoga
    Node* tail = node1;   // initially head and tail same

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 17);
    insertAtTail(tail, 19);
    print(head);

    // pehle se kuch data bhi chahiye tabhi to middle mai insert hoga, uske liye tail waale ko rehnde dete hai
    insertAtAnyPosition(head, 3, 22);
    print(head);


    return 0;
}