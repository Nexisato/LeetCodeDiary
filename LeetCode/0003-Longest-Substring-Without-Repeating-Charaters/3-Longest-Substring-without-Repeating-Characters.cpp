/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/0003-Longest-Substring-Without-Repeating-Charaters/3-Longest-Substring-without-Repeating-Characters.cpp
 * @Description:
 */
/*
LeetCode 3: Longest Substring without Repeating Characters
Description:
Given a string s, find the length of the longest substring without repeating characters.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
思路：滑动窗口
1. 用两个指针表示字符串某子串的左右边界
2. 在每一步的操作中，我们会将左指针向右移动一格，表示
    【我们开始枚举下一个字符作为起始位置】，然后我们可以不断地向右移动右指针，但需要保证
                两个指针所限定的子串中无重复字符
    在移动结束后，这个子串就对应着以左指针开始的，不包含重复字符的最长子串，我们记录下这个子串的长度
3. 枚举结束后，找到最长子串长度即为答案

*/
class Solution {
public:
	/*
	    int lengthOfLongestSubstring(string s) {
	        if (s.length() == 0) return 0;
	        unordered_map<char, int> table;
	        int maxL = 0, cur = 0;
	        for (int i = 0; i < s.length(); i++) {
	            ++cur;
	            if (++table[s[i]] > 1) {
	                --cur;
	                maxL = max(maxL, cur);
	                int j = i - 1;
	                while (j >=0 && s[j] != s[i])
	                    j--;
	                cur = i - j;
	               // memset(table, 0, 26 * sizeof(int));
	               table[s[i]] = 1;
	            }
	        }
	        maxL = max(maxL, cur);
	        return maxL;
	    }*/
	int lengthOfLongestSubstring(string s) {
		int length = s.length();
		if (length == 0)
			return 0;
		unordered_set<char> table;
		int rPtr = -1, maxL = 0;
		for (int i = 0; i < length; i++) {
			if (i != 0)
				table.erase(s[i - 1]);
			while (rPtr + 1 < length && !table.count(s[rPtr + 1])) {
				table.insert(s[rPtr + 1]);
				++rPtr;
			}
			maxL = max(maxL, rPtr - i + 1);
		}
		return maxL;
	}
};
/*
思路：滑动窗口
1. 一开始的时候left和right重合，left不动，right向右扩张，直到[left,
right]中恰有一个重复元素
2. 若子区间内[left, right]中有重复元素，则[left, right + 1]直到最后都有重复元素
3. left不断右移，直到刚好越过right指向的重复元素，更新最大长度
4. 重复上述过程，直到right到达字符串末尾
*/
class Solution_2 {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() < 2)
			return s.length();
		vector<int> table(128, 0); //记录字符出现次数
		int maxL = 0;
		for (int left = 0, right = 0; right < s.length(); right++) {
			table[(int)s[right]]++;
			while (table[(int)s[right]] > 1) {
				table[(int)s[left]]--;
				left++;
			}
			maxL = max(maxL, right - left + 1);
		}
		return maxL;
	}
};
int main() {
	string s = "abba";
	Solution ss;
	cout << ss.lengthOfLongestSubstring(s) << endl;
	return 0;
}