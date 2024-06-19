/*
@Description:
Given a binary string s, return the minimum number of character swaps to make it
alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal.
For example, the strings "010" and "1010" are alternating, while the string "0100" is
not.

Any two characters may be swapped, even if they are not adjacent.

Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
思路：
只有两种情况
1. "1010.."奇数位为0，偶数位为1
2. "0101.."奇数位为1，偶数位为0

对应位遇到不同的数，diff + 1，最终diff结果除以2即可
*/
class Solution {
public:
	int minSwaps(string s) {
		int n = s.length();
		int n0 = count(s.begin(), s.end(), '0');
		int n1 = count(s.begin(), s.end(), '1');
		int res = INT32_MAX;
		//"0101.."
		if (n0 == (n + 1) / 2 && n1 == n / 2) {
			int diff1 = 0;
			for (int i = 0; i < n; ++i)
				if (s[i] - '0' != (i % 2))
					++diff1;
			res = min(res, diff1 / 2);
		}
		//"1010.."
		if (n1 == (n + 1) / 2 && n0 == n / 2) {
			int diff2 = 0;
			for (int i = 0; i < n; ++i)
				if (s[i] - '0' == (i % 2))
					++diff2;
			res = min(res, diff2 / 2);
		}
		if (res == INT32_MAX)
			return -1;
		return res;
	}
};
int main() {
	string s = "111000";
	Solution ss;
	int res = ss.minSwaps(s);
	cout << res << endl;

	return 0;
}