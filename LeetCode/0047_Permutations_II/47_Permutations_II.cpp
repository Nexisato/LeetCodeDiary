/*
LeetCode 47II: Permutations II
@Description:
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if (used[i] == false) {
                used[i] = true;
                path.emplace_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};
int main() {

    return 0;
}