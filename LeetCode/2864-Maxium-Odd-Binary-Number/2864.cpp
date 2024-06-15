/*
 * @Date: 2024-03-13 08:01:18
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2864-Maxium-Odd-Binary-Number/2864.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string maximumOddBinaryNumber(string s) {
		int n = s.length();
		int idx = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == '1')
				swap(s[idx++], s[i]);
		swap(s[idx - 1], s[n - 1]);
		return s;
	}
};

int main() { return 0; }