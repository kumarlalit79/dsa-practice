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



bool detectLoop(Node* head){

    // empty list ki condition check karli
    if (head == NULL)
    {
        return false;
    }

    map<Node* , bool> visited;
    Node* temp = head; // ek temp node bana di jiske through mai poor list ko traverse kar pau

    while (temp != NULL)
    {
        // check karlo ki pehle se kisi ko true mark to nahi kiya
        if (visited[temp] == true)
        {
            // agr tru hai to loop present hai
            cout << "Cycle/Loop is present on element : " << temp -> data << endl;
            return true;
        }
        
        // agr cycle/loop prsent nahi hai jb bhi kisi node pe jao to use visited mark kardo
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
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
    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected!" << endl;
    }

    // Case 2: Manually create a loop (tail->next points to 30)
    tail->next = head->next->next; // loop created

    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected!" << endl;
    }

    return 0;
}
