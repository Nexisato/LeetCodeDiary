/*
 * @Date: 2024-03-07 07:59:19
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/2575-Find-the-Divisibility-Array-of-a-String/2575.cpp
 * @Description:
 */
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> divisibilityArray(string word, int m) {
		const int n = word.length();
		vector<int> res(n, 0);
		long long cur = 0;
		for (int i = 0; i < n; ++i) {
			cur = (cur * 10 + (word[i] - '0')) % m;
			res[i] = (cur == 0);
		}

		return res;
	}
};
int main() { return 0; }