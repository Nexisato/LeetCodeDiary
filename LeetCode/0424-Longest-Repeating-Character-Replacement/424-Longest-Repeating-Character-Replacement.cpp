/*
LeetCode 424: Longest Repeating Character Replacement
@author: Nexisato
@Description:
Given a string s that consists of only uppercase English letters, you can perform at most k
operations on that string.

In one operation, you can choose any character of the string and change it to any other
uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get
after performing the above operations.

Note:
Both the string's length and k will not exceed 10^4.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 维护目前窗口的单个字符的最大出现次数，
2. 剩下的字符的出现次数之和不超过k，窗口就可以继续加大，否则缩小
*/
class Solution {
public:
	int characterReplacement(string s, int k) {
		unordered_map<char, int> table;
		int left = 0, right = 0;
		int maxAppear = 0, maxL = 0;
		for (; right < s.size(); right++) {
			table[s[right]]++;
			maxAppear = max(maxAppear, table[s[right]]);
			if (right - left >= maxAppear + k) {
				table[s[left]]--;
				left++;
			}
			maxL = max(maxL, right - left + 1);
		}
		return maxL;
	}
};
int main() { return 0; }