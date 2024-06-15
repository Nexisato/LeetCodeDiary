/*
Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Constraints:
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//思路：横向扫描：扫描前两个字符串的公共前缀，再对整个字符串vector进行遍历，不断减少lcp的长度
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";
		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			prefix = longestCommonPrefix(prefix, strs[i]);
			if (prefix.length() == 0)
				return "";
		}
		return prefix;
	}
	string longestCommonPrefix(const string& s1, const string& s2) {
		int length = min(s1.length(), s2.length());
		int index = 0;
		while (index < length && s1[index] == s2[index])
			index++;
		return s1.substr(0, index);
	}
};
int main() { return 0; }