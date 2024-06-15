/*
LeetCode 477: Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the
corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs
of the integers in nums.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
*/
#include <algorithm>
#include <iostream>
#include <vector>
//再写#include <bits/stdc++.h>我就是傻逼
//再写using namespace std我就是傻逼

/*
思路：逐位统计
不可用O(n^2)的做法
nums[i]最大为10^9 < 2^30，因此检查30位即可
对于nums中的所有元素，若有c个第i位为0，(n-c)个第i位为1，则第i位的汉明距离为 c * (n - c)
*/
class Solution {
public:
	int totalHammingDistance(std::vector<int>& nums) {
		int n = nums.size();
		int res = 0;
		for (int i = 0; i < 30; ++i) {
			int c = 0;
			for (auto& num : nums)
				c += (num >> i) & 1;
			res += c * (n - c);
		}
		return res;
	}
};
int main() { return 0; }