#include <bits/stdc++.h>
using namespace std;

/*
思路：


*/
class Solution {
public:
	int specialArray(vector<int>& nums) {
		int x = -1, n = nums.size();
		int maxNum = *max_element(nums.begin(), nums.end());
		int l = 0, r = maxNum;
		for (int y = l; y <= r; ++y) {
			int count = 0;
			for (const auto& num : nums)
				if (num >= y)
					++count;
			if (y == count) {
				x = y;
				break;
			} else
				continue;
		}

		return x;
	}
};
int main() { return 0; }