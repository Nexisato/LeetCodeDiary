/*
LeetCode 5666: Palindrome Partitioning IV
Description:
Given a string s, return true if it is possible to split the string s into three
non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

Constraints:
3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 简单的中心扩展法以O(N^2)的时间复杂度找出所有回文串
2. 枚举第一段和第二段的结束位置，检查能否分成三个回文串
*/
class Solution {
public:
	bool checkPartitioning(string s) {
		int N = s.size();
		// palin[l][r]表示string[l]~string[r]为回文串
		vector<vector<bool>> palin(N, vector<bool>(N));
		for (int i = 0; i < N; i++) {
			int l = i, r = i;
			while (l >= 0 && r < N && s[l] == s[r]) {
				palin[l][r] = true;
				l--;
				r++;
			}
			l = i, r = i + 1;
			while (l >= 0 && r < N && s[l] == s[r]) {
				palin[l][r] = true;
				l--;
				r++;
			}
		}
		for (int i = 0; i + 2 < N; i++)
			for (int j = i + 1; j + 1 < N; j++) {
				if (palin[0][i] && palin[i + 1][j] && palin[j + 1][N - 1])
					return true;
			}
		return false;
	}
};
int main() { return 0; }