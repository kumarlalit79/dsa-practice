#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // constructor
    Node(int _data){
        this -> data = _data;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int value = this -> data; // yani current obj ka data
        if (this-> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    
    if (tail == NULL) // it means empty list
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }// 1st case handle ho gaya, uske baad to sabke liye same hi case chal raha hai.
    else{ // else means list empty nahi hai
        // assuming that the element is present in the list

        Node* curr = tail;
        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        
        // loop ke bahar aa gaye mtlb element found ho gaya, or curr uske upper hai
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
    
}

void print(Node* tail){
    Node* temp = tail;

    // single node agr hai to usko ham print nahi karwa payenge, so iske liye do while likh re
    do
    {
       cout << tail -> data << " "; 
       tail = tail -> next;
    }while (tail != temp);

    cout << endl;
}

int main(){

    Node* tail = NULL;
     
    // wo case jab aap empty list mai insert kr re ho
    insertNode(tail, 5, 3);  // 3 insert ho jayega
    print(tail);

    // ab mai keh ra ki, 3 ek element lena(upper jo 3 daala tha) or uske aage 5 daal dena
    insertNode(tail, 3, 5); 
    print(tail);

    insertNode(tail, 5, 7); 
    print(tail);

    insertNode(tail, 7, 9); 
    print(tail);


    // ab beech mai daalna shuru karte hai
    insertNode(tail, 5, 6); // 5 ke aage 6 daal do 
    print(tail);

    insertNode(tail, 9, 10); 
    print(tail);
    return 0;
}