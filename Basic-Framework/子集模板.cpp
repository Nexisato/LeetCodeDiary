#include <bits/stdc++.h>
using namespace std;

/*
用一个长度为n的二进制数来表示所有的子集，每一位对应nums每一位取还是不取
如：1010表示取集合的第1个数和第3个数组成子集
*/
void subSet(vector<int>& nums, vector<vector<int>>& sub) {
	int n = nums.size();
	int tot = 1 << n;
	for (int i = 0; i < tot; ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				tmp.emplace_back(nums[j]);
		sub.emplace_back(tmp);
	}
}

int main() { return 0; }