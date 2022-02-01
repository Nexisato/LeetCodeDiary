/*
LeetCode :209
Description:
Given an array of n positive integers and a positive integer s, 
find the minimal length of a contiguous subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

Follow up:
If you have figured out the O(n) solution, try coding another solution 
of which the time complexity is O(n log n). 
*/
#include<bits/stdc++.h>
using namespace std;
/*
思路：双指针法/滑动窗口法
1. 从第0项开始不断累加 sum
2. 一旦 sum 超过 s,记录当前子序列长度
3. 不断剔除当前子序列的首项，直到它小于s

notes:
窗口是什么？：满足sum>=s的最小长度连续子数组
窗口如何移动：若当前窗口值大于等于s,即需要缩小
窗口的结束位置：即遍历数组的指针，起始位置即数组的起始位置
时间复杂度：O(n) 空间复杂度:O(1)
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int slowPtr = 0;
        int sum = 0;
        int curLength = 0;
        for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++) {
            sum += nums[fastPtr];
            while (sum >= s) {
                curLength = fastPtr - slowPtr + 1;
                result = curLength <= result ? curLength : result;
                sum -= nums[slowPtr++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    Solution ss;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << ss.minSubArrayLen(7, nums) << endl;
    return 0;
}