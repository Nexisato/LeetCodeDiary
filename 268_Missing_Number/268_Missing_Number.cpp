/*
LeetCode: 268 Missing Number
Description:
Given an array nums containing n distinct numbers in the range [0, n], 
return [the only number] in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity 
and O(n) runtime complexity?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 求和作差：0~N 的和为 N*(N+1)/2，减去数组中 N 个数之和，即可得结果
2. 位运算：XOR 异或运算满足结合律，并且对一个数进行两次完全的异或后会得到原来的结果，因此
    先得到[0..n]的异或值，再对数组中每一个数字进行一次异或运算
    未缺失的数字在 [0...n] 和 nums 数组中各出现了一次，因此异或后得到0
    缺失的数字只在[0...n]中出现一次，因此与0异或后得到最终结果为缺失数字值
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += nums[i];
        int res = N * (N + 1) / 2;
        return res - sum; 
    }
    int missingNumber_xor(vector<int> &nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++)
            res ^= i ^ nums[i];
        return res;
    }
};

int main() {

    return 0;
}