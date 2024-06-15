/*
LeetCode 1269: Number of Ways to Stay in the Same Place After Some Steps
@Description:
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position
to the right in the array or stay in the same place  (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly
steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

Constraints:
1 <= steps <= 500
1 <= arrLen <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划
1. 在每一步操作中，可以左移、右移、固定指针
2. 下一步操作的指针位置，可以由上一步的同一位置、或者左边一位、或者右边一位移动而来
3. dp[i][j]表示在第i步在j位置的方案数
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]

时间优化：
    随着steps的推进，可到达的位置越来越小，因此edge可以优化
空间优化：
    利用滚动数组状态压缩
*/
class Solution {
public:
	int numWays(int steps, int arrLen) {
		const int MOD = 1000000007;
		//由于指针最终要回到原点，因此数组长度过大时没有意义
		int maxR = min(arrLen - 1, steps / 2 + 1);
		int dp[maxR + 1];
		memset(dp, 0, sizeof(int) * (maxR + 1));
		int last[maxR + 1];
		memset(last, 0, sizeof(int) * (maxR + 1));
		last[0] = 1;
		for (int i = 1; i <= steps; ++i) {
			int edge = min(i, maxR);
			for (int j = 0; j <= edge; ++j) {
				if (j == 0)
					dp[j] = (last[j] + last[j + 1]) % MOD;
				if (j == edge)
					dp[j] = (last[j] + last[j - 1]) % MOD;
				else
					dp[j] = (last[j] + last[j - 1] + last[j + 1]) % MOD;
			}
			memcpy(last, dp, sizeof(int) * (maxR + 1));
		}
		return dp[0];
	}
};
int main() { return 0; }