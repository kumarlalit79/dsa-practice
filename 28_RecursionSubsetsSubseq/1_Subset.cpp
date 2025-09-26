#include <iostream>
#include <vector>
using namespace std;

class Solution {

/*
    variable ke kaam

1 - vector<int> nums : 
    Purpose: Ye tumhara input array hai jisme se subsets generate karne hai.
    Example: {1, 2, 3}
    Kaam: Ye array decide karega ki kaunse elements subset mai aa sakte hai.

2 - vector<int> output
    Purpose: Ye temporary vector hai jo current subset ko hold karta hai.
    Example: Agar recursion mai {1,3} subset ban raha hai, to output = {1,3}
    Kaam: Jab recursion index ke end tak pahuchta hai, ye subset ans mai push kar diya jata hai.

3 - int index
    Purpose: Ye current position batata hai nums array me.
    Kaam: Har recursion call mai decide karta hai ki kaunsa element include/exclude karna hai.
    Example:
    index = 0 → element = 1
    index = 1 → element = 2
    index = 2 → element = 3

4. vector<vector<int>> &ans
    Naam: ans
    Purpose: Ye final result hai jisme saare generated subsets store hote hai.
    Type: vector of vector → har subset ek vector, aur sab subsets ek 2D vector me stored.
    Why &: & lagaya hai taaki reference pass ho aur recursion me ye copy na ho, direct same memory mai update ho jaye.
    Kaam: Jab recursion ke base case me index = nums.size() ho jata hai, tab current subset output ko ans mai add kar dete hai.
*/

private:
    void solveFn(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) { // &ans likha hai dhyan dena warna copy pass ho jayega, yaha se ref pass kr re
        
        // base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // exclude current element → move to next
        solveFn(nums, output, index + 1, ans);

        // include current element → add it to output then recurse
        int element = nums[index];
        output.push_back(element);
        solveFn(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solveFn(nums, output, index, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    // Sample input
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = obj.subsets(nums);

    // Print result
    cout << "All subsets are:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
