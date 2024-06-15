/*
LeetCode 5676: Minimum Changes To Make Alternating Binary String
@Description:
You are given a string s consisting only of the characters '0' and '1'.
In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal.
For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

Constraints:
1 <= s.length <= 10^4
s[i] is either '0' or '1'.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
分为 0 开头 和 1 开头的两种情况
*/
class Solution {
private:
	int dfs(char c, const string& s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != c)
				++cnt;
			c = c ^ 1;
		}
		return cnt;
		/*
		    return min(dfs('0', s), dfs('1', s));
		*/
	}

public:
	int minOperations(string s) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] % 2 == i % 2)
				++cnt1;
			else
				++cnt2;
		}
		return min(cnt1, cnt2);
	}
};
int main() { return 0; }