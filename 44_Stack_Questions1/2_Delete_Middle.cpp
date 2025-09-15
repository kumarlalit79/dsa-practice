#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &inputStack , int count , int size){

    // base case
    if (count == size / 2) // that means aap middle pe pahuch chuke hai
    {
        inputStack.pop(); // to middle ko pop kardo
        return ;
    }
    
    
    int topElement = inputStack.top(); // top element nikaal liye
    inputStack.pop(); // thhodi der ke liye top element ko pop kardo, jo side mai rakha tha


    // RR
    solve(inputStack,count+1,size);

    // ab Recursive call se jab wapas aa raha hoon, to jo element side mai rakha tha use wapas include kardlo
    inputStack.push(topElement);


}

void deleteMiddle(stack<int> &inputStack , int size){
    int count = 0;
    solve(inputStack , count , size);
}


int main(){

    stack<int> st;

    // stack me elements push karte hai
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int size = st.size();

    // middle element delete karte hai
    deleteMiddle(st, size);

    cout << "Stack after deleting middle element: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}