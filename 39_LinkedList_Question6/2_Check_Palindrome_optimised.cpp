#include<iostream>
#include<vector>
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

// function to find middle - slow or fast pointer leke. slow 1 step chalta or fast 2 step. we've already done it
Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next; // fast ko 2 baar aage bada diya
        slow = slow -> next; // slow ko 1 baar aage bada diya
    }
    
    // isse slow mid bhi aa gaya hoga, usko ab return kardo
    return slow;

}

Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if (head == NULL || head -> next == NULL) // checking if list empty || ya list mai single element hai
    {
        return true;
    }

    // step 1 - find mid
    Node* middle = getMid(head);

    // step 2 - reverse list after middle
    Node* temp = middle -> next;

    // ab jo reverse hua usko middle waali node ke next mai jod do
    middle -> next = reverseLL(temp);

    // step 3 - compare both half
    Node* head1 = head;
    Node* head2 = middle -> next;

    while (head2 != NULL)
    {
        if (head1 -> data != head2 -> data)
        {
            return false;
        }
        
        // wrna dono ko aage badhao if head1 and head2 equal hai
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // step 4 : repeate step 2, restore the list
    temp = middle -> next;
    middle -> next = reverseLL(temp);

    return true;
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
    
    // Create linked list
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    cout << "Original List: ";
    print(head);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome " << endl;
    } else {
        cout << "The list is NOT a palindrome " << endl;
    }

    cout << "List after function (restored): ";
    print(head);
    
    return 0;
}
