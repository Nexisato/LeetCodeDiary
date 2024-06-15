/*
LeetCode 561: Array Partition I
@Description:
Given an integer array nums of 2n integers, group these integers into n pairs
(a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized.
Return the maximized sum.

Constraints:
1 <= n <= 10^4
nums.length == 2 * n
-10^4 <= nums[i] <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：投机取巧
1. 由于我们要选择 最小值之和的最大值，因此在分配数字对的时候，应最大化两数之间较小的值
2. 应当按照升序顺序两两配对
3. 升序排序数组，结果返回数组间隔2相加的和
*/
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i += 2) {
			sum += nums[i];
		}
		return sum;
	}
};
int main() {
	vector<int> nums = {6, 2, 6, 5, 1, 2}; // 1 2 2  5 6 6
	Solution ss;
	cout << ss.arrayPairSum(nums) << endl;
	return 0;
}