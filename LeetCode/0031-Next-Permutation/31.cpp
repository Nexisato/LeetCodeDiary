/*
 * @Date: 2024-02-23 11:44:50
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0031-Next-Permutation/31.cpp
 * @Description:
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// 思路：
// 1. 从右往左找到第一个非递增的数，记为i
// 2. 从右往左找到第一个比nums[i]大的数，记为j
// 3. 交换nums[i]和nums[j]
// 4. 反转nums[i+1, n-1]
// 时间复杂度：O(n)
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		const int n = nums.size();
		// 从右向左找到第一个递减的
		// 找到小数
		int i = n - 2;
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			--i;
		}
		// 找到大数
		if (i >= 0) {
			int j = n - 1;
			while (j >= i && nums[j] <= nums[i])
				--j;
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};
int main() { return 0; }