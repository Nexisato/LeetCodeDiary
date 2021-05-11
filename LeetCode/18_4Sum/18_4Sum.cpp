/*
LeetCode 18: 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums 
such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

Constraints:
0 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针+递归
1. 先对nums升序排序
2. 递归解决nSum
*/

class Solution {
private:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target) {
        vector<vector<int>> res;
        if (n < 2 || nums.size() < n) 
            return res;
        if (n == 2) {
            int l = start, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                int lVal = nums[l], rVal = nums[r];
                if (sum < target)
                    while(l < r && nums[l] == lVal)
                        l++;
                else if (sum > target)
                    while (l < r && nums[r] == rVal)
                        r--;
                else {
                    res.push_back({nums[l], nums[r]});
                    while(l < r && nums[l] == lVal)
                        l++;
                    while (l < r && nums[r] == rVal)
                        r--;
                }
            }
        }
        else {
            for (int i = start; i < nums.size(); i++) {
                int value = target - nums[i];
                vector<vector<int>> pairs = nSum(nums, n - 1, i + 1, value);
                for (vector<int>& pair : pairs) {
                    pair.push_back(nums[i]);
                    res.push_back(pair);
                }
                while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return res;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
       vector<vector<int>> res = nSum(nums, 4, 0, target);
       return res;
    }
};
int main() {

    return 0;
}