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

bool isCircular(Node* &head){

    if (head == NULL)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    if (slow == fast)
    {
        cout << "Loop present at " << slow -> data << endl;
        return true;
    }
    
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    print(head);

    bool check = isCircular(head);
    if (check)
    {
        cout << "Yes, LL is Circular" << endl;
    }
    else{
        cout << "No, LL is't Circular" << endl;
    }

    tail -> next = head -> next -> next;
    check = isCircular(head);
    if (check)
    {
        cout << "Yes, LL is Circular" << endl;
    }
    else{
        cout << "No, LL is't Circular" << endl;
    }

    return 0;
}