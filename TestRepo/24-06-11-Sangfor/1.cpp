/**
 * raw question: leetcode 76- Minimum Window String
 * 最小覆盖子串
 * 需要用滑动窗口，先移动右指针，直到满足条件，再移动左指针，直到不满足条件
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (auto&& c : t)
			++need[c];
		string res = "";
		int valid_count = 0, start = -1, len = INT32_MAX;
		for (int left = 0, right = 0; right < s.size();) {
			char c = s[right];
			++right;
			if (need.count(c)) {
				++window[c];
				if (window[c] == need[c])
					++valid_count;
			}
			while (valid_count == need.size()) {
				if (right - left < len) {
					len = right - left;
					start = left;
				}
				char d = s[left];
				if (need.count(d)) {
					if (window[d] == need[d])
						--valid_count;
					--window[d];
				}
				++left;
			}
		}
		return len == INT32_MAX ? "" : s.substr(start, len);
	}
};

int main() { return 0; }