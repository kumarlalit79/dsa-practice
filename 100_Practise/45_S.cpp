#include<iostream>
#include<stack>
using namespace std;

class Stack{
    
    public:
    int size;
    int top1;
    int top2;
    int* arr;

    Stack(int s){
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    void push1(int element){
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        
    }

    void push2(int element){
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        
    }


    int pop1(){
        if (top1 >= 0)
        {
            int element = arr[top1];
            top1--;
            return element;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if (top2 >= 0)
        {
            int element = arr[top2];
            top2--;
            return element;
        }
        else{
            return -1;
        }
    }
    
};

int main(){

    Stack s(10);

    s.push1(11);
    s.push1(12);
    cout << "Popped" << s.pop1() << endl;
    
    s.push2(200);
    s.push2(300);
    cout << "Popped" << s.pop2() << endl;

    return 0;
}