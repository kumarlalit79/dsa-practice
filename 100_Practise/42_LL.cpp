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

Node* sortList(Node* &head){

    if (head == NULL)
    {
        return NULL;
    }

    int zeroCount = 0;
    int twoCount = 0;
    int oneCount = 0;
    
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp -> data == 0)
        {
            zeroCount++;
        }
        else if (temp -> data == 1)
        {
            oneCount++;
        }
        else if (temp -> data == 2)
        {
            twoCount++;
        }
        temp = temp -> next;
    }
    
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp -> data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp -> data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);

    print(head);
    head = sortList(head);
    print(head);

    return 0;
}