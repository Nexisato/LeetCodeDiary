/*
LeetCode 1438 : Longest Continuous Subarray with Absolute Diff Less Than or Equal to
Limit
@Description:
Given an array of integers nums and an integer limit, return the size of the longest
non-empty subarray such that the absolute difference between any two elements of this
subarray is less than or equal to limit.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. left和right维护滑动窗口
2.
map的key记录滑动窗口中的整数，相应的整数的个数记录为value，且map的key自动按照升序顺序存储
3. 不断增加right扩大窗口，直到窗口中的极差大于limit
4. 不满足限制，增加left
5. 重复上述过程，直到right达到窗口最右侧
*/
class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		int left = 0, right = 0;
		map<int, int> table;
		int maxL = 0;
		while (right < nums.size()) {
			table[nums[right]]++;
			right++;
			if (table.rbegin()->first - table.begin()->first <= limit) {
				maxL = max(maxL, right - left);
				continue;
			}
			if (--table[nums[left]] == 0)
				table.erase(nums[left]);
			left++;
		}
		return maxL;
	}
};
int main() {
	vector<int> nums = {2, 2, 2, 4, 4, 2, 2, 2, 2};
	int limit = 0;
	Solution ss;
	cout << ss.longestSubarray(nums, limit) << endl;
	return 0;
}