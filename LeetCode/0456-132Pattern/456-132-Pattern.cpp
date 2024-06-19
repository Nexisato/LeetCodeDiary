/*
LeetCode 456: 132 Pattern
@Description:
Given an array of n integers nums, a 132 pattern is a subsequence of three integers
nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n)
solution?

Constraints:
n == nums.length
1 <= n <= 10^4
-10^9 <= nums[i] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：单调栈
1. 遍历的位置为nums[k]
2. 向前0..j-1找到最小元素nums[i]，向后j+1...n-1找到最大元素nums[k]
3. 维护一个单调递减栈，这样最大元素在栈底，次大元素在栈底的上方。
- 求任何位置左边最小的元素nums[i]
- 在3的右边建立单调递减栈，从右向左遍历，pop出的最后一个元素就是比3小的最大元素nums[k]
- 判断如果nums[i] < nums[k]，说明得到一个132模式
*/
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> st;
		int n = nums.size(), numK = INT32_MIN;
		for (int i = n - 1; i >= 0; --i) {
			if (nums[i] < numK)
				return true;
			//有弹出，说明从后往前遍历有上凸元素，且弹出值为132模式中下标最右侧的
			while (!st.empty() && st.top() < nums[i]) {
				numK = max(numK, st.top());
				st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
};
int main() {

	vector<int> nums = {9, 7, 8, 4, 5, 2, 0, 9, 6};
	Solution ss;
	ss.find132pattern(nums);
	return 0;
}