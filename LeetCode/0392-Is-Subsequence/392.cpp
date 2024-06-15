/*
 * @Date: 2024-01-10 16:26:45
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0392_Is_Subsequence/392.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		const int n = s.length(), m = t.length();
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (s[i] == t[j]) {
				i++;
			}
			j++;
		}
		return i == n;
	}
};
int main() { return 0; }