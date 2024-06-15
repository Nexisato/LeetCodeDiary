/*
Description: LeetCode704
Given a sorted (in ascending order) integer array nums of n elements and a target value,
write a function to search target in nums.
If target exists, then return its index, otherwise return -1.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//思路：BinarySearch
	//时间复杂度：O(logN) 空间复杂度O(1)
	int search(vector<int>& nums, int target) {
		if (!nums.size())
			return -1;
		int low = 0, high = nums.size() - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			else if (target < nums[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		return -1;
	}
};

int main() {
	vector<int> nums = {1, 4, 5, 7, 8, 9, 10, 12, 15, 22, 23, 27, 32, 35};
	Solution ss;
	cout << ss.search(nums, 8);
	return 0;
}