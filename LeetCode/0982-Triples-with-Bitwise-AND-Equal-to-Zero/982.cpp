#include <bits/stdc++.h>
using namespace std;

/*
思路：按照最大值设置掩码进行枚举
*/
class Solution {
public:
	int countTriplets(vector<int>& nums) {
		vector<int> table(1 << 16, 0);
		for (int num : nums) {
			for (int x : nums) {
				table[num & x]++;
			}
		}
		int res = 0;
		for (int y : nums) {
			for (int i = 0; i < (1 << 16); i++)
				if ((y & i) == 0) { //注意  & 和 == 的优先级
					res += table[i];
				}
		}
		return res;
	}
};
int main() { return 0; }