/*
LeetCode 377: Combination Sum IV
@Description:
Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 
Follow up: What if negative numbers are allowed in the given array? 
How does it change the problem? What limitation we need to add to the question to allow negative numbers?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：按照target大小开数组

*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto num : nums) {
                if (num <= i && dp[i - num] < INT32_MAX - dp[i])
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};
int main() {
    Solution ss;
    vector<int> nums;
    int target;

    return 0;
} 