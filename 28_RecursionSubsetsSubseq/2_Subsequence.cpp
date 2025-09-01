#include <iostream>
#include <vector>
using namespace std;

void solveFunc(string str, string output, int index, vector<string>& ans){

    // base case
    if (index >= str.length())
    {
        ans.push_back(output);
        return ;
    }

    // exclude call
    solveFunc(str, output, index+1, ans);
    
    // include
    char element = str[index];
    output.push_back(element);
    solveFunc(str, output, index+1, ans);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;

    solveFunc(str, output, index, ans);
    return ans;
}

int main() {
    
    string str = "abcd";   // sample input
    vector<string> result = subsequences(str);

    cout << "All subsequences are:\n";
    for (auto s : result) {
        cout << (s.empty() ? "\"\"" : s) << endl;  // empty subsequence ko clearly show karne ke liye
    }

    return 0;
}
