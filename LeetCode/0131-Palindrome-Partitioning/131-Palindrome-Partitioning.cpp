/* TODO
LeetCode 131: Palindrome Partitioning
@Description:
Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：回溯+动态规划
1. 假设当前搜索到字符串的第i个字符，且s[0, ..,
i-1]位置的所有字符已经被分割成若干个回文串
*/
class Solution {
private:
	vector<vector<bool>> f;
	vector<vector<string>> res;
	vector<string> tmp;
	int n;
	void dfs(const string& s, int i) {
		if (i == n) {
			res.push_back(tmp);
			return;
		}
		for (int j = i; j < n; ++j) {
			if (f[i][j]) {
				tmp.push_back(s.substr(i, j - i + 1));
				dfs(s, j + 1);
				tmp.pop_back();
			}
		}
	}

public:
	vector<vector<string>> partition(string s) {
		n = s.length();
		f.assign(n, vector<bool>(n, true));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
			}
		}
		dfs(s, 0);
		return res;
	}
};

class Solution_backtracking {
private:
	vector<vector<string>> res;
	vector<string> path;

	vector<vector<bool>> isPalindrome;
	// bool isPalindrome(const string& s, int l, int r) {
	//     for (int i = l, j = r; i < j; ++i, --j) {
	//         if (s[i] != s[j]) return false;
	//     }
	//     return true;
	// }
	void computePalindrome(const string& s) {
		int n = s.size();
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < s.size(); ++j) {
				if (j == i)
					isPalindrome[i][j] = true;
				else if (j - i == 1) {
					isPalindrome[i][j] = (s[i] == s[j]);
				} else {
					isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
				}
			}
		}
	}

	void backtracking(const string& s, int startIndex) {
		if (startIndex >= s.size()) {
			res.push_back(path);
			return;
		}
		for (int i = startIndex; i < s.size(); ++i) {
			if (isPalindrome[startIndex][i]) {
				string elem = s.substr(startIndex, i - startIndex + 1);
				path.push_back(elem);
				backtracking(s, i + 1);
				path.pop_back();
			} else {
				continue;
			}
		}
	}

public:
	vector<vector<string>> partition(string s) {
		isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
		computePalindrome(s);
		backtracking(s, 0);
		return res;
	}
};
int main() { return 0; }