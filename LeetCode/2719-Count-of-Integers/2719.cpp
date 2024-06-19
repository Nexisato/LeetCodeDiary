/*
 * @Date: 2024-01-16 00:09:00
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2719_Count_of_Integers/2719.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 数位 DP，可以计算差值 0~num2 的个数，然后减去 0~num1 的个数
class Solution {
private:
	const int modulo = 1e9 + 7;
	int range_count(const string& str, int min_sum, int max_sum) {
		const int n = str.length();
		int upper = min(9 * n, max_sum) + 1;
		vector<vector<int>> dp(n, vector<int>(upper, -1));

		// dfs 用于计数，sum 为当前数字和，is_limit 表示是否有上界限制
		// 从数字 高位 到 低位（左到右）遍历
		function<int(int, int, bool)> dfs = [&](int i, int sum, bool is_limit) -> int {
			if (sum > max_sum)
				return 0;
			if (i == n)
				return sum >= min_sum ? 1 : 0;
			if (!is_limit && dp[i][sum] != -1)
				return dp[i][sum]; // 记忆化
			int upper = is_limit ? str[i] - '0' : 9;
			int res = 0;
			for (int d = 0; d <= upper; ++d) {
				res = (res + dfs(i + 1, sum + d, is_limit && d == upper)) % modulo;
			}
			if (!is_limit)
				dp[i][sum] = res;
			return res;
		};
		return dfs(0, 0, true);
	}

public:
	int count(string num1, string num2, int min_sum, int max_sum) {
		int res =
		    (range_count(num2, min_sum, max_sum) - range_count(num1, min_sum, max_sum)) %
		    modulo;
		int tmp = 0;
		for (const auto& c : num1)
			tmp += c - '0';
		if (min_sum <= tmp && tmp <= max_sum)
			++res;

		return res % modulo;
	}
};
int main() { return 0; }