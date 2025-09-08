#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* kReverse(Node* &head, int k){
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // step 1 : reverse first K nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    // ye sb pehle hi dekh chuke hai, loop se kese reverse krte hai.
    while (curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count ++ ;
    }
    
    // step 2 : aage ka recursion dekh lega.
    if (next != NULL) // agr aage waala part null nahi hai to
    {
        head -> next = kReverse(next, k); 
    }
    
    // step 3 : return head of reversed LL
    return prev;
    
}

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    
    // create list: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);

    cout << "Original List: ";
    print(head);

    int k = 2;
    head = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";
    print(head);

    return 0;
}
