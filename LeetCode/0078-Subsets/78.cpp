/*
LeetCode 78: Subsets
@Description:
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：利用组合思想
对于每一个nums[i]，从空集放到全集
*/
class Solution {
private:
	vector<vector<int>> res;
	void backtracking(vector<int>& nums) {
		res.push_back({});
		vector<int> tmp;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			int count = res.size();
			for (int j = 0; j < count; ++j) {
				tmp = res[j];
				tmp.push_back(nums[i]);
				res.push_back(tmp);
			}
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		backtracking(nums);
		return res;
	}
};
int main() { return 0; }