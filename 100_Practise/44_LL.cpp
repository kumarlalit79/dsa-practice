#include<iostream>
#include<stack>
using namespace std;

class Stack{
    
    public:
    int size;
    int top;
    int* arr;

    Stack(int s){
        this->size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int element){
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else{
            cout << "stack overflow" << endl;
        }
    }
    void pop(){
        if (top >= 0)
        {
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    }
    int peek(){
        if (top>=0)
        {
            return arr[top];
        }
        else{
            cout << "stack empty" << endl;
            return -1;
        }
    }
bool isEmpty(){
        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    st.push(22);
    st.push(43);
    st.push(44); // STACK OVERFLOW

    cout << st.peek() << endl; // o/p : 44
    
    st.pop(); // o/p : 44 removed
    
    cout << st.peek() << endl; // o/p :  43

    st.pop(); // o/p : 43 removed
    
    cout << st.peek() << endl; // o/p :  22

    st.pop(); // o/p : 22 removed
    
    cout << st.peek() << endl; // o/p :  underflow, it'll return -1

    if (st.isEmpty())
    {
        cout << "Stack is empty mere dost" << endl;
    }
    else{
        cout << "Stack is not empty mere dost" << endl;
    }
    

    return 0;
}