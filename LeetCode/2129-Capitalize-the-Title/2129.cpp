/*
 * @Date: 2024-03-11 08:20:27
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2129-Capitalize-the-Title/2129.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string capitalizeTitle(string title) {
		const int n = title.length();
		string res;
		string word;
		int curL = 0;
		for (int i = 0; i < n; ++i) {
			if (title[i] == ' ') {
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if (curL > 2)
					word[0] -= 32;
				res += word;
				word = "";
				curL = 0;
				res += ' ';

			} else {
				word += title[i];
				++curL;
			}
		}
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (word.length() > 2)
			word[0] -= 32;
		res += word;

		return res;
	}
};

int main() { return 0; }