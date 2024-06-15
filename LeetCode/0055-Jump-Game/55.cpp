/*
 * @Date: 2024-01-15 11:51:49
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0055_Jump_Game/55.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	// 非常典型的贪心算法，只需考虑每一步能跳到的最远距离即可
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
			if (i <= rightmost) {
				rightmost = max(rightmost, i + nums[i]);
				if (rightmost >= n - 1)
					return true;
			}
		}
		return false;
	}
};
int main() { return 0; }