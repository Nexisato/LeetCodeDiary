/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0300_Longest_Increasing_Subsequence/300_Longest_Increasing_Subsequence.cpp
 * @Description: 
 */
/*
LeetCode 300: Longest Increasing Subsequence
Description:
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
思路：DP
1. 定义dp[i]：以nums[i]结尾的LIS长度
2. 递推式
    base case: dp[i] = 1（包含nums[i]自身）
    对于 dp[i]，只需要找到在下标 i 之前 结尾值前比nums[i]小 的子序列
    即  dp[i] = max(dp[i], dp[j] + 1) 当 nums[j] < nums[i] , j < i
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res = max(res, dp[i]);
        return res;
    }
};
/*
思路：二分搜索 + patience sorting
1. 初始化扑克牌堆数为0
2. 从左到右遍历要处理的扑克牌
    · 二分搜索到合适的堆，并覆盖上
    · 若未搜索到，则新建堆并用当前牌覆盖
*/
class Solution_bs {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> heap(nums.size(), 0);
        int piles = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (tmp < heap[mid])
                    right = mid;
                else if (tmp > heap[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            if (left == piles)
                piles++;
            heap[left] = tmp;
        }
        return piles;
    }

};
int main() {

    return 0;
}