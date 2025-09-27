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

void circularInsertion(Node* &tail, int element, int data){

    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;
        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }
    while (tail != temp);
    
    cout << endl;
}

int main(){

    
    Node* tail = NULL;

    circularInsertion(tail, 1, 10);
    print(tail);
    
    circularInsertion(tail, 10, 11);
    print(tail);
    
    circularInsertion(tail, 11, 12);
    print(tail);

    return 0;
}