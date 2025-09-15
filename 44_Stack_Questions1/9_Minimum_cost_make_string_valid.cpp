#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str){

    // handling odd case
    if (str.length() %2 != 0)
    {
        return -1;
    }
    
    // removing valid part from string
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // agr open brace hai , to stack ke andar push kardo
        if (ch == '{')
        {
            s.push(ch);
        }
        else{ // mtlb tumhe close brace mil gaya. ch close brace hai.

            // ab 2 cheeze hongi, ya to tumhe is close brace ka open brace mil jayega or ek valid part ban jayega ya fir open brace nahi milega
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else{
                // agr open brace nahi pada to stack mai push kardo
                s.push(ch);
            }
        }

        
    }

    // stack contains invalid expresions now
        int a = 0, b = 0;
        while (!s.empty())
        {
            if (s.top() == '{')
            {
                b++;
            }
            else{
                a++;
            }
            s.pop();
        }
        int ans = (a+1)/2 + (b+1)/2;
        return ans;
}

int main() {
    string str;
    cout << "Enter expression with only { and }: ";
    cin >> str;

    int result = findMinimumCost(str);
    if (result == -1) {
        cout << "String cannot be balanced (odd length)." << endl;
    }
    else {
        cout << "Minimum reversals needed: " << result << endl;
    }

    return 0;
}

/*
    test case 1 : }}{{ 
    test case 2 : {{{{}}
*/