/*
LeetCode 87: Scramble String
@Description:
We can scramble a string s to get a string t using the following algorithm:
- If the length of the string is 1, stop.
- If the length of the string is > 1, do the following:
    - Split the string into two non-empty substrings at a random index, i.e., 
        if the string is s, divide it to x and y where s = x + y.
    - Randomly decide to swap the two substrings or to keep them in the same order. i.e., 
        after this step, s may become s = x + y or s = y + x.
    - Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, 
otherwise, return false.

Constraints:
s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lower-case English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路: 考虑使用四维dp
dp[i][j][k][h]表示 T[k...h]是否由 S[i..j]演变而来，由于变换长度 h - k = j - i
因此可以优化到三维 dp[i][j][len]，表示S中从i开始的字符串能否变化为T中j开始的字符串
dp[i][j][k] = dp[i][j][w] && dp[i + w][j + w][k - w] 或
            dp[i][j + k - w][w] && dp[i + w][j][k - w]
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        //single char
        for (int i = 0; i < n; +i)
            for (int j = 0; j < n; ++j)
                dp[i][j][1] = (s1[i] == s2[j]);

        for (int len = 2; len <= n; ++len)
            for (int i = 0; i <= n - len; ++i)
                for (int j = 0; j <= n - len; ++j)
                    for (int w = 1; w <= len - 1; ++w) {
                        bool a = dp[i][j][w] && dp[i + w][j + w][len - w];
                        bool b = dp[i][j + len - w][w] && dp[i + w][j][len - w]; 
                        if (a || b)
                            dp[i][j][len] = true;
                    }
        
        return dp[0][0][n];
    }
};
int main() {


    return 0;
}