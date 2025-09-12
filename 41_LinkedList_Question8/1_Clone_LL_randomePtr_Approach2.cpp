#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* random;
   
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) // if list is empty
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        // if list is not empty
        tail -> next = newNode;
        tail = newNode;
    }
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

Node* cloneList(Node* head){

    if (head == NULL) 
        return NULL;

    // step 1 : Create a separate clone list with only data copied
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    // traversing original list
    while (temp != NULL)
    {
        // jb tk equal nahi hai tb tak clone banate raho
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    } // yaha tak apni clone LL ban gayi hai, ab chalo step 2

    // step 2 : create a map (original -> clone)
    unordered_map<Node* , Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;   
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    
    // ab sabhi ke sabhi random pointer arrange karne hai. Assign random pointers using the map
    originalNode = head;
    cloneNode = cloneHead;
    
    while (originalNode != NULL) {
        if (originalNode->random != NULL) {
            cloneNode->random = oldToNewNode[originalNode->random];
        } else {
            cloneNode->random = NULL;
        }
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    
    return cloneHead;


}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    // Create original list: 1->2->3->4
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);

    // Assign random pointers manually
    head->random = head->next->next;       // 1->random = 3
    head->next->random = head;             // 2->random = 1
    head->next->next->random = tail;       // 3->random = 4
    tail->random = head->next;             // 4->random = 2

    cout << "Original List:" << endl;
    print(head);

    // Clone the list
    Node* clonedList = cloneList(head);

    cout << "Cloned List:" << endl;
    print(clonedList);

    return 0;
    return 0;
}