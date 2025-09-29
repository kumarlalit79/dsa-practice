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
    
    map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL)
    {
        if (visited[curr -> data] == true)
        {
            prev -> next = curr -> next;
            Node* nodeToDelete = curr;
            curr = curr -> next;
            delete nodeToDelete;
        }
        else{
            visited[curr -> data] = true;
            prev = curr;
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