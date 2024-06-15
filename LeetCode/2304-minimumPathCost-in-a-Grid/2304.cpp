#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
		const int m = grid.size(), n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int j = 0; j < n; ++j)
			dp[0][j] = grid[0][j];
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int minVal = INT32_MAX;
				for (int k = 0; k < n; ++k) {
					int tmpValue = grid[i - 1][k];
					minVal = min(minVal, dp[i - 1][k] + moveCost[tmpValue][j]); // note dp value range
				}
				dp[i][j] = grid[i][j] + minVal;
			}
		}
		int res = INT32_MAX;
		for (int j = 0; j < n; ++j)
			res = min(res, dp[m - 1][j]);
		return res;
	}
};
int main() { return 0; }