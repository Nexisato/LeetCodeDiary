/*
LeetCode 1221: Split a String in Balanced Strings
@Description:
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.

Return the maximum amount of split balanced strings.

Constraints:
1 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
/*
思路：

*/
class Solution {
public:
	int balancedStringSplit(string s) {
		int n = s.length();
		int res = 0, count = 0;
		for (char c : s) {
			c == 'L' ? ++count : --count;
			if (count == 0)
				++res;
		}
		return res;
	}
};

int main() { return 0; }