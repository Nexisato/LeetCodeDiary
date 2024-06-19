/*
Description:
Given a string, find the first non-repeating character in it and return its index. If it
doesn't exist, return -1.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	//思路：构造26个英文字母的哈希表，string中每个出现的字符由于都是小写英文字母，遇到即可+1。遍历两次字符串
	int firstUniqChar(string s) {
		int hash[26] = {0};
		for (int i = 0; i < s.size(); i++)
			hash[s[i] - 'a']++;
		for (int i = 0; i < s.size(); i++)
			if (hash[s[i] - 'a'] == 1)
				return i;
		return -1;
	}
	int firstUniqChar_1(string s) {
		unordered_map<char, int> count;
		for (char c : s)
			count[c]++;
		for (int i = 0; i < s.size(); i++)
			if (count[s[i]] == 1)
				return i;
		return -1;
	}
};

int main() {
	string s = "leetcode";
	Solution ss;
	cout << ss.firstUniqChar(s);

	return 0;
}