/*
 * @Date: 2024-01-11 10:40:05
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/2645_Minimum_Addition_to_Make_Valid_String/2645.cpp
 * @Description:
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int addMinimum(string word) {
		const int n = word.length();
		int dp[n + 1]; // dp[i] 表示前 i 个字符中构成 valid 串需要添加的最少字符数
		memset(dp, 0, sizeof(dp));
		dp[1] = 2;
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1] + 2; // i 个字符单独在一个 valid 串中
			if (i > 1 && word[i - 1] > word[i - 2]) {
				dp[i] = dp[i - 1] - 1;
				// i - 1 个字符构成的 valid 串中，最后一个字符可以和第 i 个字符构成
				// valid 串 这种情况下相当于少插入一次
			}
		}
		return dp[n];
	}
	int addMinimum_comb(string word) {
		const int n = word.length();
		int res = 1;
		for (int i = 1; i < n; ++i) {
			// 当前字符小于等于前一个字符时，说明一定不在同一组 valid 串中
			if (word[i] <= word[i - 1]) {
				++res;
			}
		}
		// res 表示 word 中有几组 valid 串
		return res * 3 - n;
	}
};
int main() { return 0; }