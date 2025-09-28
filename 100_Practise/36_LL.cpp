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

Node* reverseKgroups(Node* &head, int k){

    if (head == NULL)
    {
        return NULL;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    
    if (forward != NULL)
    {
        head -> next = reverseKgroups(forward, k);
    }

    return prev;

}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    cout << "Original" << endl;
    print(head);
    cout << "K groups" << endl;
    head = reverseKgroups(head, 2);
    print(head);

    return 0;
}