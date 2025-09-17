#include<iostream>
#include<stack>
using namespace std;

class SpecialStack{

    stack<int> s;
    int mini;

    public:
    void push(int data){
        // for 1st element
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else{
            if (data < mini)
            {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;//update mini
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return curr;        
        }else{
            int prevMinimum = mini;
            int val = 2 * mini - curr;
            mini = val; 
            return prevMinimum;
        }
    }
    int top(){
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;    
        }
        else{
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMini(){
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};



int main() {
    SpecialStack st;

    st.push(10);
    st.push(5);
    st.push(8);
    st.push(2);

    cout << "Current Min: " << st.getMini() << endl; // 2
    cout << "Top Element: " << st.top() << endl;    // 2

    cout << "Popped: " << st.pop() << endl;        // 2
    cout << "Current Min: " << st.getMini() << endl; // 5

    cout << "Popped: " << st.pop() << endl;        // 8
    cout << "Current Min: " << st.getMini() << endl; // 5

    cout << "Popped: " << st.pop() << endl;        // 5
    cout << "Current Min: " << st.getMini() << endl; // 10

    cout << "Is Empty: " << (st.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Popped: " << st.pop() << endl;        // 10
    cout << "Is Empty: " << (st.isEmpty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
