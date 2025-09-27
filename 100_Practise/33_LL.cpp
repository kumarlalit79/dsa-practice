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

void circularLLInsertion(Node* &tail, int element, int data){

    if (tail == NULL)
    {
        Node* temp1 = new Node(data);
        tail = temp1;
        temp1 -> next = temp1;
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

void print(Node* tail){

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
    circularLLInsertion(tail, 1, 10);
    print(tail);

    circularLLInsertion(tail, 10, 11);
    print(tail);

    circularLLInsertion(tail, 11, 12);
    print(tail);

    return 0;
}