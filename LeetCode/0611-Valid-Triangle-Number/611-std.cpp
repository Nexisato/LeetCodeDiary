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

class Solution {
public:
	/*
	思路：排序 + 二分
	*/
	int triangleNumber(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				// bs查找小于 nums[i] + nums[j] 特定值的最大下标
				int left = j + 1, right = n - 1, k = j;
				int target = nums[i] + nums[j];
				while (left <= right) {
					int mid = (left + right) / 2;
					if (nums[mid] < target) {
						k = mid;
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				}
				res += k - j;
			}
		}
		return res;
	}
	/*
	思路：排序 + 双指针
	*/
	int triangleNumber_twopointers(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int k = i;
			for (int j = i + 1; j < n; ++j) {
				while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
					++k;
				}
				res += max(k - j, 0);
			}
		}
		return res;
	}
};

int main() { return 0; }