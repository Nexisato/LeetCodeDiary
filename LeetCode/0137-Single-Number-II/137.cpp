/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0137-Single-Number-II/137.cpp
 * @Description: 
 */
/*
LeetCode 137: Single Number II
@Description:
Given an integer array nums where every element appears three times except for one, 
which appears exactly once. Find the single element and return it.

Constraints:

1 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each element in nums appears exactly three times except for one element which appears once.
 

Follow up: Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/
#include <iostream>
#include <unordered_map>
using namespace std;
/*
思路：
1. 哈希表，比较明显
2. 使用位运算，可以进一步降低时空复杂度
    res 的第 i 个二进制位即所有元素的第 i 个二进制位之和模3的余数
*/
class Solution {
public:
    int singleNumber_hash(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i)
            table[nums[i]]++;
        for (auto& item : table)
            if (item.second == 1)
                return item.first;
        return -1;
    }

    int singleNumber_bitManipulation(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (auto num : nums)
                count += (num >> i) & 1;
            if (count % 3)
                res |= (1 << i);
        }
        return res;
    }
};
int main() {


    return 0;
}