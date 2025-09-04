#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    
};

    // Insertion
    void insertAtHead(Node* &head, int data){ // yaha &- ref isliye liya taki mai copy nahi banana chahta, mai chahta meri original LL mai hi changes ho
        // jb bhi new data aata hai, to uske liye new node create karte hai
        Node* temp = new Node(data);

        // jo new node create ki usme se null ko jo point kar ra usko hata ke head waali node ko point karwa do
        temp -> next = head;

        // head jisko point kar ra usko hata ke new node ko point karwa do
        head = temp;

    }    

// printing / traversing LL
void print(Node* &head){
    Node* temp =  head;

    while (temp != NULL)
    {
        cout << temp -> data << " "; // temp ke andr jo data pada hai use print karwa diya
        temp = temp -> next; 
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(100);
    Node* head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtHead(head, 17);
    insertAtHead(head, 19);
    print(head);

    return 0;
}