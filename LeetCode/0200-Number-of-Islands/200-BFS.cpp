/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0200-Number-of-Islands/200-BFS.cpp
 * @Description:
 */
/*
LeetCode 200: Number of Islands
@Description:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's
(water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
思路：BFS
*/
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int res = 0;
		int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (grid[i][j] == '1') {
					++res;
					grid[i][j] = '0';
					queue<pair<int, int>> neighbours;
					neighbours.emplace(i, j);
					while (!neighbours.empty()) {
						auto q = neighbours.front();
						neighbours.pop();
						int x = q.first, y = q.second;
						for (int k = 0; k < 4; ++k) {
							int nx = x + d[k][0];
							int ny = y + d[k][1];
							if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
							    grid[nx][ny] == '1') {
								neighbours.emplace(nx, ny);
								grid[nx][ny] = '0';
							}
						}
					}
				}
		return res;
	}
};
int main() { return 0; }