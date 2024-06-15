/*
 * @Date: 2024-03-01 22:49:19
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0442-Find-All-Duplicates-in-Array/442.cpp
 * @Description:
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/**
桶排序思维

* TX 面试题原题，要求一次遍历，不开辟额外的空间
鉴于 数组大小在 1～n，可以将 k 放在 k - 1 的位置上
遍历到 i 的时候，通过 while 循环可以将第 i 个位置的元素复位
*/
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			while (nums[i] != 0 && nums[i] != i + 1) {
				if (nums[i] == nums[nums[i] - 1]) {
					res.push_back(nums[i]);
					nums[i] = 0;
					break;
				}
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		return res;
	}

	vector<int> findDuplicates_neg(vector<int>& nums) {
		int n = nums.size();
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			int num = nums[i];
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0) {
				nums[idx] = -nums[idx];
			} else {
				res.push_back(idx + 1);
			}
		}

		return res;
	}
};

int main() { return 0; }