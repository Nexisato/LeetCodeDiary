/*
LeetCode 91: Decode Ways
@Description:
A message containing letters from A-Z can be encoded into numbers using the following mapping:
- "A" -> "1"
- "B" -> "2"
..
- "Z" - > "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters
using the reverse of the mapping above (there may be multiple ways).
For example, "11106" can be mapped into:
- "1 1 10 6" -> "AAJF"
- "11 10 6" -> "KJF"
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划
对于给定的字符串s，假设长度为n，字符分别为 s[1]、s[2]...s[n]
假设dp[i]表示字符串s的前i个字符的解码方法数，最后一次解码使用的方法
第一种情况：
    使用一个字符s[i]进行解码，那么只要s[i]不为0，即可被解码成A~I某个字母 （个位数编码）
    - dp[i] = dp[i - 1] (s[i] != 0)
第二种情况
    使用两个字符s[i - 1]和s[i]进行编码，s[i - 1]不为0，且s[i - 1]和s[i]组成的整数小于等于26，
可以被解码成 J - Z中某个字母
    - dp[i] = dp[i - 2] (s[i - 1] != 0 且 10 * s[i - 1] + s[i] <= 26)
dp[0] = 1，表示空字符串只有一种解码方式
*/
class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] != '0')
				dp[i] += dp[i - 1];
			if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};
int main() { return 0; }