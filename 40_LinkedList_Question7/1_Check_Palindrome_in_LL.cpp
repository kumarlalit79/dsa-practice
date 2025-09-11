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

void insertAtTail(Node* &head, Node* &tail, int value) {
    
    Node* temp = new Node(value);

    if (head == NULL) // if list is empty
    {
        head = temp;
        tail = temp;
        return;
    }
    else{
        // if list is not empty
        tail -> next = temp;
        tail = temp;
    }
    
}

Node* add(Node* first, Node* second){

    // step 1
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    // step 2 : find sum . add common length nodes
    while (first != NULL && second != NULL)
    {
        int sum = carry + first -> data + second -> data;
        int digit = sum % 10;
        
        // create node and add in answer LL
        insertAtTail(ansHead , ansTail, digit);

        carry = sum / 10;

        first = first -> next; // first ko aage badhao
        second = second -> next; // second ko aage badhao
    }
    
    // step 2 : remaining nodes of first list
    while (first != NULL)
    {
        int sum = carry + first -> data;
        int digit = sum % 10;
        insertAtTail(ansHead , ansTail, digit);
        carry = sum / 10;

        first = first -> next; // first ko aage badhao
    }

    // step 3 : remaining nodes of second list
    while (second != NULL)
    {
        int sum = carry + second -> data;
        int digit = sum % 10;
        insertAtTail(ansHead , ansTail, digit);
        carry = sum / 10;

        second = second -> next; // second ko aage badhao
    }
    
    // maan lo dono LL same length ki thi pr carry bach gaya
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead , ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}



Node* addTwoList(Node* first, Node* second){

    // step 1 : reverse input LL
    first = reverseLL(first);
    second = reverseLL(second);

    // step 2 : add'em
    Node* ans = add(first, second);

    // step 3 : reverse answer waali LL
    ans = reverseLL(ans);

    return ans;
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
    
    // Create first number: 1->2->3  (represents 123)
    Node* first = NULL;
    Node* firstTail = NULL;
    insertAtTail(first, firstTail, 3);
    insertAtTail(first, firstTail, 4);
    insertAtTail(first, firstTail, 5);
    

    // Create second number: 4->5 (represents 45)
    Node* second = NULL;
    Node* secondTail = NULL;
    insertAtTail(second, secondTail, 4);
    insertAtTail(second, secondTail, 5);

    cout << "First number: ";
    print(first);

    cout << "Second number: ";
    print(second);

    // Add two numbers
    Node* result = addTwoList(first, second);

    cout << "Result: ";
    print(result);
    return 0;
}
