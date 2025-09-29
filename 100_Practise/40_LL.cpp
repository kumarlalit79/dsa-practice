#include<iostream>
#include<map>
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

Node* uniqueLL(Node* &head){
    if (head == NULL)
    {
        return NULL;
    }
    Node* curr = head;
    while (curr != NULL)
    {
        if (curr -> next != NULL && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    
    return head;
    
}


int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 3);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);

    cout << "Original LL" << endl;
    print(head);
    cout << "Unique LL" << endl;
    uniqueLL(head);
    print(head);

    return 0;
}