/*
 * @Date: 2024-02-03 10:00:25
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0030-Substring-With-Concatenation-of-All-Words/30.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 这个题得做一下映射
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty())
			return res;
		int n = s.size(), m = words.size(), len = words[0].size();
		unordered_map<string, int> table;
		for (auto& word : words) {
			table[word]++;
		}
		// 这里小于 i < len 是因为我们要从每个位置开始，然后每次移动 len 个位置
		// 存在重复的情况，所以我们要从每个位置开始
		for (int i = 0; i < len; i++) {
			int left = i, right = i, count = 0;
			unordered_map<string, int> window;
			while (right + len <= n) {
				string cur = s.substr(right, len);
				right += len;
				if (table.count(cur)) {
					window[cur]++;
					count++;
					while (window[cur] > table[cur]) {
						string temp = s.substr(left, len);
						window[temp]--;
						left += len;
						count--;
					}
					if (count == m) {
						res.push_back(left);
					}
				} else {
					window.clear();
					count = 0;
					left = right;
				}
			}
		}
		return res;
	}
};
int main() { return 0; }