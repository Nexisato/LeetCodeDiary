/*
 * @Date: 2024-01-15 11:29:53
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0097_Interleaving_String/97.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		const int n1 = s1.length();
		const int n2 = s2.length();
		const int n3 = s3.length();
		if (n1 + n2 != n3)
			return false;
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		dp[0][0] = true;
		// s1 的前 i 个字符能否构成 s3 的前 i 个字符
		for (int i = 1; i <= n1; ++i)
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		// s2 的前 j 个字符能否构成 s3 的前 j 个字符
		for (int j = 1; j <= n2; ++j)
			dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
		for (int i = 1; i <= n1; ++i)
			for (int j = 1; j <= n2; ++j) {
				// s1 的前 i 个字符和 s2 的前 j 个字符能否构成 s3 的前 i + j 个字符
				dp[i][j] =
				    (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}

		return dp[n1][n2];
	}
};
int main() { return 0; }