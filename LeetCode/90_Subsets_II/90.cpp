/*
LeetCode 90: SubsetsII
@Description:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& nums, bool preSelected, int index) {
        if (index == nums.size()) {
            res.push_back(tmp);
            return;
        }
        dfs(nums, false, index + 1);
        //若未选择上一个数，且当前数字与上一个数字相同，则跳过当前生成的子集
        if (preSelected == false && index > 0 && nums[index - 1] == nums[index])
            return;
        tmp.push_back(nums[index]);
        dfs(nums, true, index + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, false, 0);
        return res;
    }
};
int main() {
    vector<int> nums = {1, 2, 2};
    Solution ss;
    vector<vector<int>> res = ss.subsetsWithDup(nums);
    return 0;
}