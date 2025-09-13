#include<iostream>
using namespace std;


class TwoStack{

    int* arr;
    int top1;
    int top2;
    int size;

    public:
        // constructor
        TwoStack(int _size){
            this->size = _size;
            top1 = -1;
            top2 = _size;
            arr = new int[_size];
        }

    // push in stack 1
    void push1(int num){
        
        if (top2 - top1 > 1) // atleast 1 space available hona chahiye tabhi to push kar payenge
        {
            top1++;
            arr[top1] = num;
        }
        else{
            cout << "stack overflow kar gaya" << endl;
        }
    }

    // push in stack 2
    void push2(int num){
        
        if (top2 - top1 > 1) // atleast 1 space available hona chahiye tabhi to push kar payenge
        {
            top2--;
            arr[top2] = num;
        }
        else{
            cout << "stack overflow kar gaya" << endl;
        }
    }

    // pop from stack 1 and returned popped element
    int pop1(){ 
        if (top1 >= 0)// koi element present hona chahiye tbhi pop karunga
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // pop from stack 2 and returned popped element
    int pop2(){ 
        if (top2 < size)// koi element present hona chahiye tbhi pop karunga
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};


int main() {
    TwoStack ts(10);  // ek hi array me 10 size ka do stack

    // Stack 1 me push karte hai
    ts.push1(10);
    ts.push1(20);
    ts.push1(30);

    // Stack 2 me push karte hai
    ts.push2(100);
    ts.push2(200);
    ts.push2(300);

    // Pop from stack 1
    cout << "Popped from stack 1: " << ts.pop1() << endl; // 30
    cout << "Popped from stack 1: " << ts.pop1() << endl; // 20

    // Pop from stack 2
    cout << "Popped from stack 2: " << ts.pop2() << endl; // 300
    cout << "Popped from stack 2: " << ts.pop2() << endl; // 200

    // Ab push1 aur push2 check karte hai overflow ke liye
    ts.push1(40);   
    ts.push1(50);
    ts.push1(60);
    ts.push1(70);
    ts.push1(80);
    ts.push1(90);  // yaha tak array fill ho jayega
    ts.push1(100); // Ye overflow dikhayega kyuki space nahi bacha

    return 0;
}
