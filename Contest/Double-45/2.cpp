/*
LeetCode 5658: Maximum Absolute Sum of Any Subarray
@Description:
You are given an integer array nums. The absolute sum of a subarray 
[numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4 
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：不要用滑动窗口了!!!
连续子序列和的绝对值最大有两种情况：
- sum[j] - sum[i] (分别为累加和数组的最大值和最小值)
- abs(sum[i]) 
1. 建立累加和数组，并对该数组排序
2. 连续子序列和的最大值 nums[i] + nums[i + 1] + ... + nums[j] = sum[j] - sum[i - 1]
    故设定maxSum初始值为 sum[N - 1] - sum[0]
3. 遍历sum数组，看是否有abs(sum[i]) > maxSum
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if (nums.size() == 1) return abs(nums[0]);
        int maxSum = 0;
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i];
        sort(sum.begin(), sum.end());
        maxSum = sum[sum.size() - 1] - sum[0];
        for (int i = 0; i < nums.size(); i++) {
            maxSum = (maxSum > abs(sum[i])) ? maxSum : abs(sum[i]);
        }
        return maxSum;
    }
};
int main() {
    Solution ss;
    vector<int> nums = {1,-3,2,3,-4};
    cout << ss.maxAbsoluteSum(nums) << endl;
    return 0;
}