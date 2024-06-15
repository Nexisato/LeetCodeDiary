/*
LeetCode 395: Longest Substring At Least K Repeat Characters
@Description:
Given a string s and an integer k, return the length of the longest substring of s
such that the frequency of each character in this substring is greater than or equal to k.

Constraints:
1 <= s.length <= 10^4
s consists of only lowercase English letters.
1 <= k <= 105。
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 维护两个计数器：滑动窗口内的字符种类数目tot 以及 当前出现次数小于k且不为0的字符种类数less
2. 对于给定字符数量t，在窗口[l, r]内，若tot > t，则不断移动左边界，并实时更新tot，直到 tot <= t
    · 若[l, r]存在出现次数小于k(包括0)的字符，则该子串不符合题意
3. 遍历26种字符t，利用滑动窗口将窗口中的字符个数限制到t，并在less == 0时返回一个最长子串值
*/
class Solution {
public:
	int longestSubstring(string s, int k) {
		int maxL = 0;
		int n = s.length();
		for (int t = 1; t <= 26; ++t) {
			int left = 0, right = 0;
			vector<int> table(26, 0);
			int less = 0;
			int tot = 0;
			while (right < n) {
				table[s[right] - 'a']++;
				if (table[s[right] - 'a'] == 1) {
					less++;
					tot++;
				}
				if (table[s[right] - 'a'] == k)
					less--;
				while (tot > t) {
					table[s[left] - 'a']--;
					if (table[s[left] - 'a'] == k - 1)
						less++;
					if (table[s[left] - 'a'] == 0) {
						tot--;
						less--;
					}
					left++;
				}
				if (less == 0)
					maxL = max(maxL, right - left + 1);
				right++;
			}
		}
		return maxL;
	}
};
/*
思路： 分治法
对于某个子串s，若存在某个字符c, 其出现次数大于0小于k, 则任何包含c的字符串都不符合条件，由此可得分治算法：
1. 遍历找到出现次数大于0且小于k的字符的位置
2. 以这些字符出现的位置为split节点，将字符串拆分成更小的一部分
3. 返回这些被分割子串中的满足条件的最大子串长度
*/
class Solution_dc {
public:
	int longestSubstring(string s, int k) {
		unordered_map<char, int> table;
		for (auto& c : s)
			table[c]++;
		vector<int> splits;
		int n = s.length();
		for (int i = 0; i < n; ++i)
			if (table[s[i]] < k)
				splits.emplace_back(i);
		if (splits.size() == 0)
			return n;
		int maxL = 0;
		int left = 0;
		for (int i = 0; i < splits.size(); ++i) {
			int len = splits[i] - left;
			if (len >= k && len > maxL)
				maxL = max(maxL, longestSubstring(s.substr(left, len), k));
			left = splits[i] + 1;
		}
		if (left < n - 1)
			maxL = max(maxL, longestSubstring(s.substr(left, n - 1 - left + 1), k));
		return maxL;
	}
};
int main() { return 0; }