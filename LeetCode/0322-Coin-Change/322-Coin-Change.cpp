/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0322_Coin_Change/322_Coin_Change.cpp
 * @Description:
 */
/*
LeetCode: 322 Coin Change
Description:
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
思路：
1. base case：amount = 0时，返回0
2. 状态：目标金额amount作为原问题和子问题的变化量
3. 选择：每选择一枚硬币相当于减少了目标金额
4. dp数组定义：金额为 n 时所需要的最小硬币数量
*/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		int N = amount;
		vector<int> dp(N + 1, INT16_MAX);
		dp[0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int coin : coins) {
				if (i - coin < 0)
					continue;
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return (dp[amount] == INT16_MAX) ? -1 : dp[amount];
	}
};
int main() { return 0; }