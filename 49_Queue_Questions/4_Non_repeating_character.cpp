#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string firstNonRepeating(string A){

    unordered_map<char , int> count;
    queue<char> q;
    string ans = "";

    // input string pe traverse karo
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // character ka count increase kardo
        count[ch]++;

        // queue mai push kardo
        q.push(ch);

        // koi bhi cheez repeating hai to use pop kardo
        while (!q.empty())
        {
            if(count[q.front()] > 1){
                // agr count grater than 1 hai that means repeating character hai, jo ki mujhe nahi chahiye
                q.pop();
            }
            else{
                // non repeating character mil gaya. store karlo answer mai
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            // that means koi non repeating character nahi hai
            ans.push_back('#');
        }
        
    }
    return ans;
}

int main() {
    string stream = "aabc";
    string result = firstNonRepeating(stream);

    cout << "First non-repeating characters in stream: " << result << endl;
    // Expected output: "a#bb"

    return 0;
}
