/*
LeetCode 115: Distinct Subsequences
@Description:
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string 
by deleting some (can be none) of the characters without disturbing the 
remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Constraints:
0 <= s.length, t.length <= 1000
s and t consist of English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：明显的dp
等会，这不是LCS吗?
- 二维dp数组：dp[i][j]表示长为 i, j 的字符串 s,t 相匹配的子序列个数
- s[i - 1] == t[j - 1]时，分为两部分（即等效于是否删除末尾元素）
    · dp[i - 1][j - 1]：去掉公共字符匹配的不同子序列个数
    · dp[i - 1][j]：去掉源串的公共字符，再匹配的不同子序列的个数
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        //s删除个别字符后，能够得到空串——仅有全部删除一种情况
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        return dp[m][n];
    }
};
int main() {


    return 0;
}