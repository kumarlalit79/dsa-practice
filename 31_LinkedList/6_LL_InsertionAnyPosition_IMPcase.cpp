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

// sbse best insertion ka code, kisi bhi position chahhe 1st ya last pe insert kr sakte.
void insertAtAnyPosition(Node* &head , Node* &tail,  int position , int data){ 
    Node* temp = head;    
    
    // insert at first position
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

    // insert at last position
    if (temp -> next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp->next;
    temp -> next = nodeToInsert;
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


    return 0;
}