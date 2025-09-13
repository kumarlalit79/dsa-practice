#include<iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class using Linked List
class Stack {
    public:
        Node* top; // Points to the top node of the stack

        // Constructor
        Stack() {
            top = NULL; // Initially stack is empty
        }

    // PUSH operation -> Insert element at the top
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; // Link new node with the previous top
        top = newNode;       // Move top to new node
    }

    // POP operation -> Remove top element
    void pop() {
        if (top == NULL) {
            cout << "STACK UNDERFLOW" << endl;
            return;
        }
        Node* temp = top;
        top = top->next; // Move top one step down
        delete temp;     // Free memory
    }

    // PEEK operation -> Return top element
    int peek() {
        if (top == NULL) {
            cout << "STACK is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Print full stack (for debugging)
    void print() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(99);

    st.print(); // Shows current stack (top at left)

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "After one pop, Top: " << st.peek() << endl;

    st.pop();
    st.pop();
    st.pop();

    if (st.isEmpty())
        cout << "Stack is empty mere dost" << endl;
    else
        cout << "Stack is not empty mere dost" << endl;

    return 0;
}
