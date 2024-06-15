/*
 * @Date: 2024-02-06 09:19:23
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LCP/0030-MagicTower.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int magicTower(vector<int>& nums) {
		int n = nums.size();
		int res = 0;
		long long sum = accumulate(nums.begin(), nums.end(), 1LL);
		if (sum < 0) {
			return -1;
		}
		// 最小堆
		priority_queue<int, vector<int>, greater<int>> pq;
		long long cur = 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 0) {
				pq.push(nums[i]);
			}
			cur += nums[i];
			if (cur <= 0) {
				res++;
				cur -= pq.top();
				pq.pop();
			}
		}
		return res;
	}
};
int main() { return 0; }