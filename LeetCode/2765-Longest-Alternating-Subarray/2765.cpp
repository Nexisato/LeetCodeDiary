/*
 * @Date: 2024-01-23 09:10:38
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2765-Longest-Alternating-Subarray/2765.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int alternatingSubarray(vector<int>& nums) {
		const int n = nums.size();
		int res = -1;
		int l = 0, r = 0;
		while (r < n) {
			int count = 0;
			while (r + 1 < n) {
				int diff = nums[r + 1] - nums[r];
				// 奇
				if (count % 2) {
					if (diff == -1) {
						++r;
					} else {
						break;
					}
				} else {
					if (diff == 1) {
						++r;
					} else {
						break;
					}
				}
				++count;
			}
			res = max(res, r - l + 1);
			++l;
			r = l;
		}

		return res > 1 ? res : -1;
	}
	// 不用这么麻烦
	int alternatingSubarray(vector<int>& nums) {
		const int n = nums.size();
		int res = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int length = j - i + 1;
				// 下面这个转移挺关键，奇数位比开头高 1，偶数位相等
				if (nums[j] - nums[i] == (length - 1) % 2)
					res = max(res, length);
				else
					break;
			}
		}

		return res;
	}
};
int main() { return 0; }