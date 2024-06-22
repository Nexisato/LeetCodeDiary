/*
LeetCode 279: Perfect Squares
@Description:
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect
squares while 3 and 11 are not.

Constraints:
1 <= n <= 10^4
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
思路：背包DP
*/
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			dp[i] = i;
			int up = static_cast<int>(sqrt(i));
			for (int j = 1; j * j <= i; ++j)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		return dp[n];
	}
};
int main() { return 0; }