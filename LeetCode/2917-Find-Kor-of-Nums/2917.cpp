/*
 * @Date: 2024-03-06 16:40:09
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2917-Find-Kor-of-Nums/2917.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKOr(vector<int>& nums, int k) {
		int table[32] = {0};
		int res = 0;
		for (auto&& num : nums) {
			int cur = num;
			for (int i = 0; i < 32; ++i) {
				table[i] += (cur & (1 << i)) ? 1 : 0;
			}
		}
		for (int i = 0; i < 32; ++i)
			if (table[i] >= k)
				res += (1 << i);
		return res;
	}
};

int main() { return 0; }