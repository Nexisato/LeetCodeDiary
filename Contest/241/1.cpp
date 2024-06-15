/*
LeetCode 5759:  Sum of All Subset XOR Totals
*/
#include <bits/stdc++.h>
using namespace std;
/*
补充：位运算求子集！

*/
class Solution {
public:
	int subsetXORSum(vector<int>& nums) {
		int n = nums.size();
		int res = 0, tot = 1 << n;
		for (int i = 1; i < tot; ++i) {
			int tmp = 0;
			int idx = 0, j = i;
			while (j > 0) {
				if (j & 1)
					tmp ^= nums[idx];
				++idx;
				j >>= 1;
			}
			res += tmp;
		}
		return res;
	}
};
int main() {
	int a = 63;
	int res = 0;
	for (int i = 0; i <= a; ++i)
		res += i;
	cout << res << endl;
	return 0;
}