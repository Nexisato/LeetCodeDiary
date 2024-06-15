/*
LeetCode 611: Valid Triangle Number
@Description:
Given an integer array nums, return the number of triplets chosen from the array that can make triangles
if we take them as side lengths of a triangle.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
/*
思路：
*/
class Solution {
private:
	/*
	返回最后一个小于 x 的元素的下标
	*/
	int binarySearch(vector<int>& nums, int l, int r, int x) {
		int index = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < x) {
				index = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		return index;
	}

public:
	int triangleNumber(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int l = 0; l < n - 2; ++l)
			for (int r = l + 1; r < n - 1; ++r) {
				int l1 = nums[l], l2 = nums[r], upper = l1 + l2;
				if (l1 == 0)
					break;
				int index = binarySearch(nums, r + 1, n - 1, upper);
				res += (index == -1) ? 0 : (index - r);
			}
		return res;
	}
};

int main() { return 0; }