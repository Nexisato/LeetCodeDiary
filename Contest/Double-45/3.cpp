/*
LeetCode 5659: Minimum Length of String After Deleting Similar Ends
@Description:
Given a string s consisting only of characters 'a', 'b', and 'c'.
You are asked to apply the following algorithm on the string any number of times:
-Pick a non-empty prefix from the string s where all the characters in the prefix are
equal. -Pick a non-empty suffix from the string s where all the characters in this
suffix are equal. -The prefix and the suffix should not intersect at any index. -The
characters from the prefix and suffix must be the same. -Delete both the prefix and the
suffix.

Return the minimum length of s after performing the above operation any number of times
(possibly zero times).

Constraints:
1 <= s.length <= 10^5
s only consists of characters 'a', 'b', and 'c'.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针
1. left < right，首尾字符不相等，直接返回长度
2. left >= right，考虑全字符相等和中间有1个其他字符的情况
    -
若全字符相等，从left处检查或从right处检查相邻元素是否相等，相等返回0即可，否则直接返回1
*/
class Solution {
public:
	int minimumLength(string s) {
		int left = 0, right = s.length() - 1;
		while (true) {
			if (s[left] != s[right])
				break;
			while (left < right && s[left] == s[left + 1])
				left++;
			while (left < right && s[right] == s[right - 1])
				right--;
			if (left < right) {
				left++;
				right--;
			} else {
				if (left > 0 && s[left] == s[left - 1])
					return 0;
				else if (right < s.length() - 1 && s[right] == s[right] + 1)
					return 0;
				else
					return 1;
			}
		}
		return right - left + 1;
	}
};
int main() { return 0; }