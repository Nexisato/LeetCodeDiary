/*
Description: LeetCode 912
Given an array of integers nums, sort the array in ascending order.

Constraints:
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/
#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//思路：快速排序yyds:
//选择一个pivot，前一部分都比它小，后一部分都比它大，再递归排序两部分子数组
//时间复杂度:O(nlogn) 空间复杂度:O(n)~O(logn)
class Solution {
	int partition(vector<int>& nums, int l, int r) {
		int pivot = nums[r];
		int i = l - 1;
		for (int j = l; j <= r - 1; ++j) {
			if (nums[j] <= pivot)
				swap(nums[++i], nums[j]);
		}
		swap(nums[i + 1], nums[r]);
		return i + 1;
	}

	int randomized_partition(vector<int>& nums, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(nums[r], nums[i]);
		return partition(nums, l, r);
	}

	void randomized_quicksort(vector<int>& nums, int l, int r) {
		if (l < r) {
			int pos = randomized_partition(nums, l, r);
			randomized_quicksort(nums, l, pos - 1);
			randomized_quicksort(nums, pos + 1, r);
		}
	}

public:
	vector<int> sortArray(vector<int>& nums) {
		srand((unsigned)time(NULL));
		randomized_quicksort(nums, 0, (int)nums.size() - 1);
		return nums;
	}
};
int main() {
	vector<int> nums = {9, 7, 8, 4, 5, 2, 0, 9, 6};
	Solution ss;
	ss.sortArray(nums);
	for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
		cout << *(it) << " ";
	return 0;
}