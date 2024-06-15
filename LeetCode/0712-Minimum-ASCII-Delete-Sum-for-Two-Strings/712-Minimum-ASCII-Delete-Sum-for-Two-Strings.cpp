/*
LeetCode 712: Minimum ASCII Delete Sum for Two Strings
Description:
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Note:
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 类似于LCS，将LCS矩阵存储的长度单元更换为ascii值单元
2. 结果为两个string的ASCII和减去两个string的LCS（共2倍）
*/
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int m = s1.length(), n = s2.length();
		vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (s1[i - 1] == s2[j - 1])
					table[i][j] = table[i - 1][j - 1] + s1[i - 1];
				else
					table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		int sum = 0;
		for (int i = 0; i < m; i++)
			sum += s1[i];
		for (int j = 0; j < n; j++)
			sum += s2[j];
		return sum - 2 * table[m][n];
	}
};
int main() { return 0; }