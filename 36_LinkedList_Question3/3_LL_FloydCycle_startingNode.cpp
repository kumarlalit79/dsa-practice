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

Node*  floydDetectLoop(Node* head){
    if (head == NULL)
    {
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        // iske baar slow ko ek baar badhayene or fast ko do baar
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if (slow == fast)
        {
            cout << "Cycle detected at node: " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
    
}

Node* getStartingNode(Node* head){

    if (head == NULL)
    {
        return NULL;
    }
    
    // sbse pehle point of intersection chhahiye, or wo mujhe floydDetectLoop() function dega
    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;    

}

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

    // Case 1: No loop
    if (floydDetectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected!" << endl;
    }

    // Case 2: Manually create a loop (tail->next points to 30)
    tail->next = head->next->next; // loop created

    if (floydDetectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected!" << endl;
    }


    Node* loop = getStartingNode(head) ;
    cout << "Loop starts at : " << loop -> data << endl; 
    return 0;
}
