/*
LeetCode 80: Remove Duplicates from Sorted Array
@Description:
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared 
at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place 
with O(1) extra memory.

Clarification:
Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array 
will be known to the caller.

Constraints:
1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针
1. 若检测到连续三个同样的数值，则记录该数值为lNum
2. 右指针+1向右遍历到第一个不等于lNum的位置
3. 数组重新赋值，更新数组当前长度
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int l = 0, r = 1;
        while (r < n - 1) {
            if (nums[l] == nums[r] && nums[r] == nums[r + 1]) {
                int lNum = nums[l];
                while (r < n - 1 && nums[r + 1] == lNum)
                    r++;
                int tmpr = l + 1;
                while (r < n)
                    nums[tmpr++] = nums[r++];
                n = tmpr;   
            }
            l++;
            r = l + 1;
        }
        nums.erase(nums.begin() + n, nums.end());
        return n;
    }
};
int main() {
    Solution ss;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int res = ss.removeDuplicates(nums);
    cout << res << endl;
    return 0;
}