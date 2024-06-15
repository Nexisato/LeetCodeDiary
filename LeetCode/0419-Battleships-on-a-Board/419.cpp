#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		const int m = board.size(), n = board[0].size();
		int res = 0;

		function<void(int, int)> dfs = [&](int i, int j) {
			if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.')
				return;
			board[i][j] = '.';
			dfs(i + 1, j);
			dfs(i - 1, j);
			dfs(i, j + 1);
			dfs(i, j - 1);
		};
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j)
				if (board[i][j] == 'X') {
					++res;
					dfs(i, j);
				}
		}

		return res;
	}
};

int main() { return 0; }