/*
LeetCode: 674 Longest Continuous Increasing Subsequence
Description:
Given an unsorted array of integers nums, return the length of the longest continuous 
increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that 
it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

Constraints:
0 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：

*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 1 , max_length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                res++;
                max_length = max(res, max_length);
            }
            else {
                if (i == nums.size())
                    break;
                else {   
                    res = 1;
                }
            }
        }
        return max_length;
    }
};
int main() {
    vector<int> nums = {1, 2, 3, 2, 3, 4, 5};
    Solution ss;
    cout << ss.findLengthOfLCIS(nums) << endl;
    return 0;
}