#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtAnyPosition(Node* &head,Node* &tail, int position, int data){
    Node* temp = head;
    if (position == 1)
    {
        insertAtHead(head , data);
        return ;
    }
    
    int count = 1;
    while (count < position - 1 )
    {
        temp = temp -> next;
        count++;
    }
    

    if (temp -> next == NULL)
    {
        insertAtTail(tail , data);
        return;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
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

int getlength(Node* &head){
    Node* temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length ++ ;
        temp = temp -> next;
    }
    return length;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    cout << node1 -> data << endl;

    insertAtHead(head, 7);
    print(head);
    insertAtHead(head, 5);
    print(head);

    insertAtTail(tail , 12);
    print(head);
    insertAtTail(tail , 14);
    print(head);

    insertAtAnyPosition(head, tail, 4 , 11);
    print(head);

    insertAtAnyPosition(head, tail, 1 , 4);
    print(head);

    insertAtAnyPosition(head, tail, 8 , 15);
    print(head);

    cout << "Length : " << getlength(head) << endl;

    return 0;
}