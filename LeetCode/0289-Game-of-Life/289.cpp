/*
 * @Date: 2024-02-07 15:53:33
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0289-Game-of-Life/289.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		const int m = board.size(), n = board[0].size();
		vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
		auto inBound = [&](int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; };
		auto countLive = [&](int x, int y) {
			int cnt = 0;
			for (auto& dir : dirs) {
				int nx = x + dir[0], ny = y + dir[1];
				if (inBound(nx, ny) && (board[nx][ny] & 1))
					++cnt;
			}
			return cnt;
		};
		// 状态转移:
		// 1：活细胞，下一轮死细胞
		// 2：死细胞，下一轮活细胞
		// 3：活细胞，下一轮活细胞
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int cnt = countLive(i, j);
				if (board[i][j] == 1) {
					if (cnt < 2 || cnt > 3)
						// 伪：标识重捕法
						board[i][j] = 1;
					else
						board[i][j] = 3;
				} else {
					if (cnt == 3)
						board[i][j] = 2;
				}
			}
		}
		for (auto& row : board) {
			for (auto& cell : row) {
				cell >>= 1;
			}
		}
	}
};
int main() { return 0; }