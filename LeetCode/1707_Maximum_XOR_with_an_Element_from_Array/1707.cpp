/*
LeetCode 1707: Maximum XOR with an Element from Array
@Description:
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. 
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, 
then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Constraints:
1 <= nums.length, queries.length <= 10^5
queries[i].length == 2
0 <= nums[j], xi, mi <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：暴力遍历会超时
应用字典树
- 

*/
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; ++i) {
            int x = queries[i][0], u = queries[i][1];
            for (int j = 0; j < n; ++j) {
                if (nums[j] <= u) {
                    int val = nums[j] ^ x;
                    res[i] = max(res[i], val);
                }
            }
            
        }
        return res;
    }
};
int main() {

    return 0;
}