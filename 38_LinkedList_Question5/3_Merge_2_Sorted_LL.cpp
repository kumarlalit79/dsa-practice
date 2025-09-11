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

// deciding kisko first banana hai
Node* mergeLists(Node* first, Node* second){

    // if only one element is present in first LL, to first ke next mai poori ki poori second LL dal do
    if (first -> next == NULL)
    {
        first -> next = second;
        return first;
    }
    

    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while (next1 != NULL && curr2 != NULL)
    {
        // ab second se first mai daalna hai to condn check kr re ki daal sakta ya nahi
        if ( (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data) )
        {

            // adding nodes in b/w the first list
            // Insert curr2 between curr1 and next1
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            // update the pointers. Move curr1 forward
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // agr us range mai lie nahi karta to pointers ko aage badha do
            // curr1 and next1 ko aaghe badhana hai
            curr1 = next1;
            next1 = next1 -> next;

            // check kr lena next1 null na pahuch gya ho, age null pahuch gya to LL khtm
            if (next1 == NULL)
            {
                curr1 -> next = curr2;
                return first;
            }
            
            
        }
        
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second) {

    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    // function to decide first and second
    if (first -> data <= second -> data)
    {
        mergeLists(first, second); // to is function mai first pehle pass kr re
    }
    else{
        mergeLists(second, first); // wrna second pehle pass kardo
    }
    
    
    
}

int main(){
    
    // First Sorted LL: 1 -> 3 -> 5
    Node* first = new Node(1);
    Node* tail1 = first;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);

    // Second Sorted LL: 2 -> 4 -> 6
    Node* second = new Node(2);
    Node* tail2 = second;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);

    cout << "First List:  ";
    print(first);
    cout << "Second List: ";
    print(second);

    Node* mergedHead = sortTwoLists(first, second);

    cout << "Merged List: ";
    print(mergedHead);

    return 0;
}
