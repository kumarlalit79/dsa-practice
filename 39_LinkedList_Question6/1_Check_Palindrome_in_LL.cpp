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

bool checkPalindrome(vector<int> arr){
    int n = arr.size();
    int s = 0; // start - i
    int e = n-1; // end - j

    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;    
        e--;
    }
    return 1;
}

bool isPalindrome(Node* head){

    // Edge case: Empty or single element LL is always palindrome
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // step 1 : create an empty array
    vector<int> arr;

    // step 2 : copying content of LL 
    Node* temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
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
    
    // =========================
    // Example 1: Palindrome LL
    // =========================
    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);

    cout << "List 1: ";
    print(head1);
    if (isPalindrome(head1)) {
        cout << "List 1 is a Palindrome\n\n";
    } else {
        cout << "List 1 is NOT a Palindrome\n\n";
    }

    // =========================
    // Example 2: Non-Palindrome LL
    // =========================
    Node* node2 = new Node(1);
    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail2, 2);
    insertAtTail(tail2, 3);

    cout << "List 2: ";
    print(head2);
    if (isPalindrome(head2)) {
        cout << "List 2 is a Palindrome\n";
    } else {
        cout << "List 2 is NOT a Palindrome\n";
    }

    return 0;
}
