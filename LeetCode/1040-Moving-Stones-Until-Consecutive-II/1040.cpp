#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 好难啊....
 *
 */
class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
		int n = stones.size();
		sort(stones.begin(), stones.end());
		int e1 = stones[n - 2] - stones[0] - n + 2;
		int e2 = stones[n - 1] - stones[1] - n + 2;
		int res_max = max(e1, e2);
		if (e1 == 0 || e2 == 0)
			return {min(2, res_max), res_max};

		int left = 0, max_cnt = 0;
		for (int right = 0; right < n; ++right) {
			while (stones[right] - stones[left] + 1 > n)
				++left;
			max_cnt = max(max_cnt, right - left + 1);
		}
		return {n - max_cnt, res_max};
	}
};
int main() { return 0; }