/*
LeetCode 697: Degree of Array
@Description:
Given a non-empty array of non-negative integers nums, the degree of this array is defined 
as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, 
that has the same degree as nums.

Constraints:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：记录最大频元素出现的首末位置
1.设 x 为出现次数最多的元素，和原数组度相同的最短连续子数组，必然包含了nums中的全部x，且两端恰为 x 出现的首末位置
2.符合条件的 x 可能有多个，因此需要统计每一个数出现的次数及首末位置
3.记录完信息后，找到出现次数最多且首末位置差最小的元素
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> table;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.count(nums[i])) {
                table[nums[i]][0]++;
                table[nums[i]][2] = i;
            }
            else
                table[nums[i]] = {1, i, i};
        }
        int maxCount = 0, minLen = nums.size();
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (maxCount < it->second[0]) { 
                maxCount = it->second[0];
                minLen = it->second[2] - it->second[1] + 1;
            }
            else if (maxCount == it->second[0])
                minLen = min(minLen, it->second[2] - it->second[1] + 1);
        }
        return minLen;
    }
};
int main() {
    Solution ss;
    vector<int> nums = {1, 2, 2, 3, 1};
    cout << ss.findShortestSubArray(nums) << endl;
    return 0;
}