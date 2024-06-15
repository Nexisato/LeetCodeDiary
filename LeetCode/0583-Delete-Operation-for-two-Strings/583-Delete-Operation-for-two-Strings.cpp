/*
LeetCode 583: Delete Operation for two Strings
Description:
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same,
where in each step you can delete one character in either string.

Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：DP
问题即为最长公共子序列的变体
只需各字符串长度减去公共子序列长度，即为删除次数
*/
class Solution {
private:
	int LongestCommonSequence(string text1, string text2) {
		int m = text1.length(), n = text2.length();
		vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (text1[i - 1] == text2[j - 1])
					table[i][j] = table[i - 1][j - 1] + 1;
				else
					table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		return table[m][n];
	}

public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		int c = LongestCommonSequence(word1, word2);
		return m - c + n - c;
	}
};
int main() { return 0; }