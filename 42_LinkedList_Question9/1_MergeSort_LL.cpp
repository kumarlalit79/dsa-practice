#include<iostream>
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

// merging to LL
Node* merge(Node* leftHalf, Node* rightHalf){

    // maan lo left waali LL empty hai
    if (leftHalf == NULL)
    {
        return rightHalf;
    }

    // maan lo right waali LL empty hai
    if (rightHalf == NULL)
    {
        return leftHalf;
    }

    // dummy node
    Node* ans = new Node(-1);
    Node* temp = ans;

    while (leftHalf != NULL && rightHalf != NULL)
    {
        if (leftHalf -> data < rightHalf -> data)
        {
            temp -> next = leftHalf;
            temp = leftHalf;
            leftHalf = leftHalf -> next;
        }
        else{
            temp -> next = rightHalf;
            temp = rightHalf;
            rightHalf = rightHalf -> next;
        }
    }
    
    // suppose right half poora traverse krke null hogaya but left waali LL abhi tk Null nahi hui hai
    while (leftHalf != NULL)
    {
        temp -> next = leftHalf;
        temp = leftHalf;
        leftHalf = leftHalf -> next;
    }
    
    // suppose left half poora traverse krke null hogaya but right waali LL abhi tk Null nahi hui hai
    while (rightHalf != NULL)
    {
        temp -> next = rightHalf;
        temp = rightHalf;
        rightHalf = rightHalf -> next;
    }
    ans = ans -> next;
    return ans;
}


// ye code already pehle likh chuke hai
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* mergeSort(Node* head){

    // base case
    if (head == NULL || head -> next == NULL) // LL empty hai ya already sorted hai, to kuch krne ki need hi nahi hai
    {
        return head;
    }

    // mid nikaalne ke liye fast and slow pointer waali algo use karenge
    Node* mid = findMid(head);

    // 2 half bana lo
    Node* leftHalf = head; // left half starting se shuru hota hai
    Node* rightHalf = mid -> next; // rightHalf mid ke next se shuru hota, means mide ke ek aaghe se
    mid -> next = NULL; // mid ke baad null bhi to hoga rightHalf start hone se pehle

    // ab sort krdo - recursive call ke through
    leftHalf = mergeSort(leftHalf);
    rightHalf= mergeSort(rightHalf);
    

    // ab 2 halves ko merge krdo
    Node* result = merge(leftHalf, rightHalf);

    return result;


}

int main(){


    // Step 1: Linked List create karo
    Node* head = new Node(4); // starting node
    Node* tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 3);
    insertAtTail(tail, 5);

    cout << "Original Linked List: ";
    print(head);

    // Step 2: Merge Sort call karo
    head = mergeSort(head);

    cout << "Sorted Linked List:   ";
    print(head);

    return 0;
}