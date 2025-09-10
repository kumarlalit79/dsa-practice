#include<iostream>
#include<map>
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

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return ;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* uniqueSortedLL(Node* head){

    // maan lo LL hi empty hai
    if (head == NULL)
    {
        return NULL;
    }
    
    // non empty list
    Node* curr = head;
    while (curr != NULL)
    {
        if ((curr -> next != NULL) && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next; // current ke next ke next ko ek variable mai store karwa liya hai

            // ab jo node delete karwani hai wo rakh lo
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete); // free memory

            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    
    return head;

}

int main(){
    
     // Create list with duplicates: 10 -> 20 -> 20 -> 30 -> 40 -> 40 -> 40 -> 50 -> 60 -> 70 -> 70
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 20); // duplicate
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 40); // duplicate
    insertAtTail(tail, 40); // duplicate
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    insertAtTail(tail, 70); // duplicate

    cout << "Original Sorted List (with duplicates): ";
    print(head);

    head = uniqueSortedLL(head);

    cout << "After Removing Duplicates: ";
    print(head);

    return 0;
}
