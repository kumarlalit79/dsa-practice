#include<iostream>
#include<map>
using namespace std;


class Node {
public:
    int data;
    Node* next;
   
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

Node* sortList(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    // Step 1: Count 0s, 1s, 2s, ab ek baar LL traverse karlo
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
        else if(temp -> data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }

    // count hamne nikaal liye, ab neeche LL ko traverse krke replce kr dena data do
    // Step 2: Replace data based on counts
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp -> data = 0; // temp ke data mai 0 daal diya
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
    
    // Create an unsorted list with 0s, 1s, 2s
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);

    cout << "Original List: ";
    print(head);

    head = sortList(head);

    cout << "Sorted List:   ";
    print(head);

    return 0;
}
