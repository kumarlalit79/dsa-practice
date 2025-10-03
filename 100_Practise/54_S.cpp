#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string &str){

    if (str.length() %2 != 0)
    {
        return -1;
    }
    
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else{
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    int a , b =0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else{
            a++;
        }
    }
    int ans = (a+1/2) + (b+1/2);
    return ans;
    
    

}

int main(){

    string str = "{{{{}}}}";
    
    int result = findMinimumCost(str);
    if (result == -1)
    {
        cout << "Invalid" << endl;
    }
    else{

        cout << "valid" << endl;
    }
    
    return 0;
}

/*
    test case 1 : }}{{ 
    test case 2 : {{{{}}
*/