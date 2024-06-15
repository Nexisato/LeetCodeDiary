/*
LeetCode 200: Number of Islands
@Description:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：DFS
*/
class Solution {
private:
	void dfs(vector<vector<char>>& grid, int r, int c) {
		int m = grid.size(), n = grid[0].size();

		grid[r][c] = '0';

		if (r - 1 >= 0 && grid[r - 1][c] == '1')
			dfs(grid, r - 1, c);
		if (r + 1 < m && grid[r + 1][c] == '1')
			dfs(grid, r + 1, c);
		if (c - 1 >= 0 && grid[r][c - 1] == '1')
			dfs(grid, r, c - 1);
		if (c + 1 < n && grid[r][c + 1] == '1')
			dfs(grid, r, c + 1);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int res = 0;

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (grid[i][j] == '1') {
					++res;
					dfs(grid, i, j);
				}
		return res;
	}
};

int main() { return 0; }