#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solveFn(string digits, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);// choose
            solveFn(digits, output, index + 1, ans, mapping); // explore
            output.pop_back();// backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        string output;
        int index = 0;
        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solveFn(digits, output, index, ans, mapping);
        return ans;
    }
};

int main() {
    Solution obj;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Possible combinations:\n";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
