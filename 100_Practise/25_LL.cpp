#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head ,int data){

    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void print(Node* head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data <<  " " ;
        temp = temp -> next;
    }
    cout << endl;
    
}


int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);

    print(head);
    
    return 0;
}