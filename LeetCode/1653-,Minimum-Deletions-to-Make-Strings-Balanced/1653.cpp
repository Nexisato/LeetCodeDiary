#include <bits/stdc++.h>
using namespace std;
/*
思路：分三种情况
1. 删除全部的 a
2. 删除全部的 b
3. 建立分隔点，左侧的 b 和右侧的 a 全部删除，比较上述情况的最小值
*/
class Solution {
public:
	int minimumDeletions(string s) {
		int res = 0;
		int leftb = 0, righta = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a')
				righta++;
		}
		res = righta;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a')
				righta--;
			else
				leftb++;
			res = min(res, leftb + righta);
		}
		return res;
	}
	/*
	DP: 找"aaabbb"的最大长度，若当前字符以 a 结尾，则 res++；若当前字符为 b
	，则考虑上一个字符为 a 或 b 结尾长度的最大长度加1
	*/
	int minimumDeletions_dp(string s) {
		int a = 0, b = 0, n = s.length();
		for (auto x : s) {
			if (x == 'a')
				a += 1;
			else
				b = max(a, b) + 1;
		}
		return n - max(a, b);
	}
};
int main() { return 0; }