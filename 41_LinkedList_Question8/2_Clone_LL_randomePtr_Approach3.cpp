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

    // step 1 : create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
    
    // step 2 : clone ke node ko add karna tha in b/w original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        // same step krne hai clone node ke liye
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    // step 3 : random pointer copy karne the.
    temp = head;
    while (temp != NULL)
    {
        if (temp -> next != NULL)
        {
            if (temp -> random != NULL)
            {
                temp -> next -> random = temp -> random -> next; 
            }
            else{
                temp -> next -> random = NULL; // NULL ki jgh temp -> random bhi likh sakte same aayega
            }
        }
        // mujhe isko 2 baar aage badhana hai, like pahle vertically down jayega then cross mai right, uske liye 2 baar aaghe badhana hoga
        temp = temp -> next -> next; 
    }

    // step 4 : revert changes jo step 2 mai kiye the
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if (originalNode != NULL)
        {
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    // step 5 : return ans
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