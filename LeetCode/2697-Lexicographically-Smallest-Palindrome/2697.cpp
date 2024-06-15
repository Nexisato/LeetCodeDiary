#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/**
 * 思路：
 * 回文串的构造
 * 双指针直接遍历，不一样就直接取最小的字母进行替换
 *
 */
class Solution {
public:
	string makeSmallestPalindrome(string s) {
		const int n = s.size();
		int l = 0, r = n - 1;
		while (l < r) {
			if (s[l] != s[r]) {
				s[l] = s[r] = min(s[l], s[r]);
			}
			++l;
			--r;
		}
		return s;
	}
};
int main() { return 0; }