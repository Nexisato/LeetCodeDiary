/*
 * @Date: 2024-01-28 11:26:39
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0042-Trapping-Rain-Water/42.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 双指针
	// 从两边向中间遍历，每次移动较小的那个指针
	int trap(vector<int>& height) {
		const int n = height.size();
		int l = 0, r = n - 1;
		int res = 0;
		++l;
		--r;
		int l_max = height[0], r_max = height[n - 1];
		while (l <= r) {
			l_max = max(l_max, height[l]);
			r_max = max(r_max, height[r]);

			if (l_max < r_max) {
				res += l_max - height[l];
				++l;
			} else {
				res += r_max - height[r];
				--r;
			}
		}
		return res;
	}
};
int main() { return 0; }