/*
LeetCode 567: Permutation in String
@Description:
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.

Constraints:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 只考虑滑入滑出的数据
2. 用table记录s1字符串中字符的个数
3. 遍历s2中的字符c
    · 若c在s1中出现过，count-1
    · count == 0 时，s2中恰好有一个子串为s1字符串乱序的形态
    · 窗口长度为s1 + 1时，滑出最左边的字符，若为s1中的字符则count+1

*/
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		unordered_map<char, int> table;
		for (char c : s1)
			table[c]++;
		int count = s1.length();
		int left = 0, right = 0, valid = 0;
		while (right < s2.size()) {
			if (table[s2[right++]]-- > 0)
				--count;
			if (count == 0)
				return true;
			if (right - left == s1.length() && ++table[s2[left++]] > 0)
				++count;
		}
		return false;
	}
};
int main() { return 0; }