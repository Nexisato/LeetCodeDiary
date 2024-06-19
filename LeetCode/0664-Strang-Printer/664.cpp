/*
LeetCode 664: Strange Printer
@Description:
There is a strange printer with the following two special properties:
- The printer can only print a sequence of the same character each time.
- At each turn, the printer can print new characters starting from and ending at any
place and will cover the original existing characters.

Given a string s, return the minimum number of turns the printer needed to print it.

Constraints:
1 <= s.length <= 100
s consists of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：区间DP
1. 定义dp[l][r]表示将[l, r]打印成目标结果所消耗的最小打印次数
2.
*/
class Solution {
public:
	int strangePrinter(string s) {
		int n = s.length();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int len = 1; len <= n; ++len) {
			for (int l = 0; l + len - 1 < n; ++l) {
				int r = l + len - 1;
				dp[l][r] = dp[l + 1][r] + 1;
				for (int k = l + 1; k <= r; ++k)
					if (s[l] == s[k])
						dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
			}
		}
		return dp[0][n - 1];
	}
};
int main() { return 0; }