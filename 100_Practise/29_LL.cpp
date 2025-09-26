#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int lengthLL(Node* &head){
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtNode(Node* &head, int data){

    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtNode(head,9);
    print(head);

    insertAtNode(head,8);
    print(head);

    insertAtNode(head,7);
    print(head);

    insertAtNode(head,6);
    print(head);

    insertAtNode(head,5);
    print(head);


    return 0;
}