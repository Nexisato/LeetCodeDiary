/*
 * @Date: 2024-01-20 10:38:22
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2788-Split-Strings-by-Separator/2788.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
		vector<string> res;
		for (auto& word : words) {
			int start = 0;
			int end = 0;
			while (end < word.size()) {
				if (word[end] == separator) {
					if (end - start > 0)
						res.push_back(word.substr(start, end - start));
					start = end + 1;
				}
				end++;
			}
			if (end - start > 0)
				res.push_back(word.substr(start, end - start));
		}
		return res;
	}
};
int main() { return 0; }