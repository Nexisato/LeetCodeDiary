/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/0076-Minimum-Windows-String/76-Minimum-Window-String.cpp
 * @Description:
 */
/*
LeetCode 76: Minimum Window String
@Description:
Given two strings s and t, return the minimum window in s which will contain all the
characters in t. If there is no such window in s that covers all characters in t, return
the empty string "".

Note that If there is such a window, it is guaranteed that there will always be
only one unique minimum window in s.

Constraints:
1 <= s.length, t.length <= 10^5
s and t consist of English letters.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
思路：滑动窗口
1. 初始化left，right，将索引区间[left, right) 称为一个窗口
2. 不断增加right指针扩大窗口，直到窗口中的字符串符合要求
3. 停止增加right，不断增加left缩小窗口，直到窗口中的字符串不再满足要求
4. 不断重复以上过程，直到right指针到达s串末尾
*/
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (char c : t)
			need[c]++;
		int left = 0, right = 0, valid = 0;
		int start = 0, len = INT32_MAX;
		while (right < s.size()) {
			char c = s[right];
			right++;
			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c])
					valid++;
			}
			while (valid == need.size()) {
				if (right - left < len) {
					start = left;
					len = right - left;
				}
				char d = s[left];
				left++;
				if (need.count(d)) {
					if (window[d] == need[d])
						valid--;
					window[d]--;
				}
			}
		}
		return (len == INT32_MAX) ? "" : s.substr(start, len);
	}
};
int main() {
	string s = "ATMPXAHKL";
	string t = "LKHX";
	Solution ss;
	cout << ss.minWindow(s, t) << endl;
	return 0;
}