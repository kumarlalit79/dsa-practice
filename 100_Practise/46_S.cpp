#include<iostream>
#include<stack>
using namespace std;

int main(){

    string str = "lucky";
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    
    string answer = "";
    while (!s.empty())
    {
        char ans = s.top();
        answer.push_back(ans);
        s.pop();
    }
    
    cout << answer << endl;

    return 0;
}