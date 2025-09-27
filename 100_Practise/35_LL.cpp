#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }

};

void insertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
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

int getLength(Node* &head){
    Node* temp = head;
    int lenght = 0;
    while (temp != NULL)
    {
        lenght++;
        temp = temp -> next;
    }
   return lenght; 
}

Node* getMiddle(Node* &head){
    Node* temp = head;
    int length = getLength(head);
    int mid = (length/2);
    int count = 0;

    while (count < mid)
    {
        temp = temp -> next;
        count++;
    }
    return temp;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail , 11);
    
    insertAtTail(tail , 12);
    
    insertAtTail(tail , 13);
    
    insertAtTail(tail , 14);
    
    insertAtTail(tail , 15);
    
    insertAtTail(tail , 16);
    insertAtTail(tail , 17);

    print(head);
    
    Node* ans = getMiddle(head);
    cout << "Middle : " << ans -> data << endl;


}