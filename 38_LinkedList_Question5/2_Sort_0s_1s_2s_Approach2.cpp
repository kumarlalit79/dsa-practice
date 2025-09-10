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


// check it once : // Ye version curr node ko tail se attach karega
void insertAtTail(Node* &tail, Node* curr) {
   
    tail->next = curr; // tail ke next me curr attach kiya
    tail = curr; // tail ko aage badha diya
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

    // Step 1: Dummy heads and tails banaye
    Node* zeroHead = new Node(-1); // isme -1 pada hai abhi.
    Node* zeroTail = zeroHead; // taki insertAtTail kr sake, or ye starting mai zeroHead ko point krri.               
    
    Node* oneHead = new Node(-1); // isme -1 pada hai abhi.
    Node* oneTail = oneHead; // taki insertAtTail kr sake.

    Node* twoHead = new Node(-1); // isme -1 pada hai abhi.
    Node* twoTail = twoHead; // taki insertAtTail kr sake.

    // Step 2: Original list traverse
    Node* curr = head;

    // creating seperate LL for 0,1,2
    while (curr != NULL)
    {
        int value = curr -> data; // compare krne ke liye isko le rahe hai

        if (value == 0)
        {
            insertAtTail(zeroTail , curr);
        }
        else if(value == 1){
            insertAtTail(oneTail , curr);
        }
        else if(value == 2){
            insertAtTail(twoTail , curr);
        }

        curr = curr -> next;
    }

    // now merge these 3 sublist
    // Step 3: Merge lists
    // 0 list -> 1 list (agar 1 list empty nahi hai)
    if (oneHead -> next != NULL) // that means 1 ki list Non Empty hai
    {
        zeroTail -> next = oneHead -> next;
    }
    else{
        // 1 waali list empty nikli, to 0 waali list ke aage 2 waali list laga do
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // ab dummy node ko delete maar do and head ko 1st node pe point karwa do
    head = zeroHead -> next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}

int main(){
    
    // Create unsorted list with 0s, 1s, 2s
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    // Ye insert tail normal hai list create karne ke liye
    tail->next = new Node(0); tail = tail->next;
    tail->next = new Node(2); tail = tail->next;
    tail->next = new Node(1); tail = tail->next;
    tail->next = new Node(2); tail = tail->next;
    tail->next = new Node(0); tail = tail->next;
    tail->next = new Node(1); tail = tail->next;

    cout << "Original List: ";
    print(head);

    head = sortList(head);

    cout << "Sorted List:   ";
    print(head);

    return 0;
}
