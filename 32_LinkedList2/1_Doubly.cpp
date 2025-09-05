#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int _data){
        this -> data = _data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){ // jab tk temp null nahi ho jata
        cout << temp -> data; // tb tk temp ke data ko print karwate jao 
        temp = temp -> next; // or temp ko aage badhate chale jao
    }
    cout << endl;
}

// finding LL length
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){ 
        len++;  
        temp = temp -> next; 
    }
    return len;
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    print(head);

    cout << "Length of LL = " << getLength(head) << endl;

    return 0;
}