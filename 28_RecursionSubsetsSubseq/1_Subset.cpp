#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:
    void solveFn(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) { // &ans likha hai dhyan dena warna copy pass ho jayega, yaha se ref pass kr re
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
