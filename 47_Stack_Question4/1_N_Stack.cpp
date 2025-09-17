#include<iostream>
#include<stack>
using namespace std;

class NStack{

    int *arr;
    int *top;
    int *next;

    int n , s;
    int freespot;

    public:
    // constructor
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s]; // array ko size de diya
        top = new int[n];
        next = new int[s];

        // initiliziting top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        
        // initilizing next
        for (int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }
     
        // update last index value to -1
        next[s-1] = -1;

        freespot = 0;
    }

    bool push(int x , int m) // m means stack
    {
        // check ki stack overflow to nahi kar raha
        if (freespot == -1)
        {
            cout << "Stack Overflow\n";
            return false;
        }
        
        // step 1 : find index
        int index = freespot;

        // step 2 : update free spot
        freespot = next[index];

        // step 3 : insert element into array
        arr[index] = x;

        // step 4 : update next
        next[index] = top[m-1];

        // step 5 : update top
        top[m-1] = index;

        return true;

    }

    int pop(int m){

        // check underflow condition
        if (top[m-1] == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        
        // pop ka logic push ek logic ka reverse way mai likh do neeche se upper
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];

    }

};



int main(){

    NStack stacks(3, 10); // 3 stacks, total size 10

    // Push elements
    stacks.push(10, 1); // stack 1
    stacks.push(20, 1);
    stacks.push(30, 2); // stack 2
    stacks.push(40, 3); // stack 3

    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // 20
    cout << "Popped from stack 2: " << stacks.pop(2) << endl; // 30
    cout << "Popped from stack 3: " << stacks.pop(3) << endl; // 40
    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // 10
    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // Underflow

    return 0;
}