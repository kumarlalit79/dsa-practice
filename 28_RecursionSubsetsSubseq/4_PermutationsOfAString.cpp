#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solveFn(vector<int> nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);                // choose
            solveFn(nums, ans, index + 1);             // explore
            swap(nums[index], nums[j]);                // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solveFn(nums, ans, index);
        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter size of array: "; // 3
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: "; // 1 2 3
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = obj.permute(nums);

    cout << "\nAll permutations:\n";
    for (auto& perm : result) {
        cout << "[ ";
        for (int val : perm) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}
