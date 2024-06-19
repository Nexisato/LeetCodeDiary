/*
LeetCode 581: Shortest Unsorted Continuous Subarray
@Description:
Given an integer array nums, you need to find one continuous subarray
that if you only sort this subarray in ascending order, then the whole array will be
sorted in ascending order.

Return the shortest such subarray and output its length.

Constraints:
1 <= nums.length <= 10^4
-10^5 <= nums[i] <= 10^5
 
Follow up: Can you solve it in O(n) time complexity?
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
思路：两次相反方向的单调栈
正向找最左侧的极小突变点
反向找最右侧的极大突变点

*/
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		vector<int> st;
		int l = n - 1, r = 0;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && nums[st.back()] > nums[i]) {
				l = min(l, st.back());
				st.pop_back();
			}
			st.emplace_back(i);
		}
		st.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && nums[st.back()] < nums[i]) {
				r = max(r, st.back());
				st.pop_back();
			}
			st.emplace_back(i);
		}
		return (r - l > 0) ? (r - l + 1) : 0;
	}
};
int main() {
	vector<int> nums{2, 1};
	Solution* ss = new Solution();
	int res = ss->findUnsortedSubarray(nums);
	cout << res << endl;

	return 0;
}