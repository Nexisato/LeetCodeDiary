#include <bits/stdc++.h>
using namespace std;

/*
思路：

*/
class Solution {
public:
	int partitionDisjoint(vector<int>& nums) {
		int n = nums.size();
		vector<int> min(n + 1);
		min[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; ++i)
			min[i] = (nums[i] < min[i + 1]) ? nums[i] : min[i + 1];
		for (int j = 0, max = 0; j < n - 1; ++j) {
			max = (nums[j] > max) ? nums[j] : max;
			if (max <= min[j + 1])
				return j + 1;
		}
		return -1;
	}

	int partitionDisjoint_one_traversal(vector<int>& nums) {
		int n = nums.size();
		int leftMax = nums[0], leftPos = 0, curMax = nums[0];
		for (int i = 1; i < n - 1; ++i) {
			curMax = max(curMax, nums[i]);
			if (nums[i] < leftMax) {
				leftMax = curMax;
				leftPos = i;
			}
		}
		return leftPos + 1;
	}
};
int main() { return 0; }