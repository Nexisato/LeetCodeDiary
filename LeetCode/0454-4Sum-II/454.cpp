#include <bits/stdc++.h>
using namespace std;
/**
 * @思路
 * 对称 两数之和，用 hashtable 记录 num1, num2 之和出现的次数
 *
 */
class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
	                 vector<int>& nums4) {
		int res = 0;
		unordered_map<int, int> table;
		for (int num1 : nums1)
			for (int num2 : nums2)
				table[num1 + num2]++;
		for (int num3 : nums3)
			for (int num4 : nums4)
				if (table.find(0 - (num3 + num4)) != table.end())
					res += table[0 - (num3 + num4)];
		return res;
	}
};
int main() { return 0; }