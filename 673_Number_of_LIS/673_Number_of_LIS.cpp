/*
LeetCode 673: Number of LIS
@Decription:
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Constraints:
1 <= nums.length <= 2000
-10^6 <= nums[i] <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划
1. 定义两个dp数组，dp[i]用于表示nums[i]结尾的LIS，counts[i]表示nums[i]结尾的最长递增子序列个数
2. 对于nums[i]，若在[0..i-1]中找到j,nums[i]>nums[j]，分为如下两种情况
    - dp[j] + 1 > dp[i]，则count[i] = count[j]
    - dp[j] + 1 == dp[i]，则count[i] += count[j]
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> dp(n, 1), counts(n, 1);
        int maxL = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) 
                if (nums[i] > nums[j]) {
                    //---keypoint
                    if (dp[j] + 1 > dp[i])
                        counts[i] = counts[j];
                    else if (dp[j] + 1 == dp[i])
                        counts[i] += counts[j];
                    //--keypoint
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            maxL = max(maxL, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (dp[i] == maxL)
                res += counts[i];
        return res;   
    }
};
int main() {


    return 0;
}