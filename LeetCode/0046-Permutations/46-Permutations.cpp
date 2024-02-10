/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0046-Permutations/46-Permutations.cpp
 * @Description:
 */
/*
Description:
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include <iostream>
#include <vector>
using namespace std;

/*
    思路： 回溯算法
*/
class Solution {
	vector<vector<int>> res;

private:
	void perm(vector<int>& nums, int low, int high) {
		if (low == high) {
			res.push_back(nums);
			return;
		}
		for (int i = low; i <= high; ++i) {
			swap(nums[i], nums[low]);  // 交换顺序
			perm(nums, low + 1, high); // 继续向下搜索
			swap(nums[i], nums[low]);  // 回溯，撤销交换
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		res.clear();
		perm(nums, 0, nums.size() - 1);
		return res;
	}
};

int main() { return 0; }