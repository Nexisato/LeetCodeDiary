/* TODO
LeetCode 131: Palindrome Partitioning
@Description:
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：回溯+动态规划
1. 假设当前搜索到字符串的第i个字符，且s[0, .., i-1]位置的所有字符已经被分割成若干个回文串
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
int main() {

    return 0;
}