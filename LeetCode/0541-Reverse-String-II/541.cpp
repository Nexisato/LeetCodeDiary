/*
LeetCode 541: Reverse String II
Given a string s and an integer k, reverse the first k characters for every 2k
characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them.
If there are less than 2k but greater than or equal to k characters, then reverse the
first k characters and left the other as original.

Constraints:
1 <= s.length <= 10^4
s consists of only lowercase English letters.
1 <= k <= 10^4
*/
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
/*
思路：这都忘了?orz

*/

class Solution {
public:
	string reverseStr(string s, int k) {
		int n = s.length();
		for (int i = 0; i < n; i += 2 * k)
			reverse(s.begin() + i, s.begin() + min(i + k, n));
		return s;
	}
};
int main() { return 0; }