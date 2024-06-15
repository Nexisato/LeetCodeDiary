#include <bits/stdc++.h>
using namespace std;

/*
思路：
双指针控制在 O(n) 以内

*/
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size(), k = n - 1;
		vector<int> res(n, 0);
		for (int i = 0, j = n - 1; i <= j;) {
			if (nums[i] * nums[i] < nums[j] * nums[j]) {
				res[k--] = nums[j] * nums[j];
				--j;
			} else {
				res[k--] = nums[i] * nums[i];
				++i;
			}
		}
		return res;
	}
};
int main() { return 0; }