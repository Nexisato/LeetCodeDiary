/*
 * @Date: 2024-01-30 09:45:33
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/2808-Minimum-Seconds-to-Equalize-a-Circular-Array/2808.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 考虑这样一个问题
// 对于某个数 num ，使得数组中所有的数都相等，最少需要多少次操作
// 对于某数 num 的出现位置，使得数组全部变成 num 的情况，需要 (i_{k} - i_{k-1}) 次操作，
// 1. 由于是循环数组，因此最大距离可以是 n - (i_{k} - i_{k-1})
// 最后还要除一下 2(可以相向)
class Solution {
public:
	int minimumSeconds(vector<int>& nums) {
		const int n = nums.size();
		unordered_map<int, vector<int>> table;
		for (int i = 0; i < n; ++i) {
			table[nums[i]].push_back(i);
		}
		int res = INT_MAX;
		for (auto& [num, pos] : table) {
			// 最后一个位置到第一个位置的距离
			int max_distance = pos[0] + n - pos.back();
			for (int i = 1; i < pos.size(); ++i) {
				max_distance = max(max_distance, pos[i] - pos[i - 1]);
			}
			// 这里一定要除以 2，因为可以相向而行
			res = min(res, max_distance / 2);
		}

		return res;
	}
};
int main() { return 0; }