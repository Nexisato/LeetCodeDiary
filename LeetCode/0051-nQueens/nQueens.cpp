/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0051-nQueens/nQueens.cpp
 * @Description: 
 */
/*
Description:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.

Constraints:
1<=n<=9
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<string>> res;
	// vector中每个string代表一行棋子
	void backtracking(int n, int row, vector<string>& chessboard) {
		if (row == n) {
			res.push_back(chessboard);
			return;
		}
		for (int col = 0; col < n; ++col) {
			if (isValid(row, col, chessboard, n)) {
				chessboard[row][col] = 'Q';           // 放置皇后
				backtracking(n, row + 1, chessboard); // 验证合法性
				chessboard[row][col] = '.';           // 回溯，撤销皇后
			}
		}
	}
	// Pruning: 从待放置棋子作为检查点开始遍历
	bool isValid(int row, int col, vector<string>& chessboard, int n) {
		// scan column
		for (int i = 0; i < row; i++)
			if (chessboard[i][col] == 'Q')
				return false;
		// main diagonal
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (chessboard[i][j] == 'Q')
				return false;
		// sub diagonal
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
			if (chessboard[i][j] == 'Q')
				return false;

		return true;
	}

public:
	// 思路：backtracking
	// 1. 确定函数参数
	// 2. 单层搜索逻辑
	// 3. 验证合法性
	vector<vector<string>> solveNQueens(int n) {
		res.clear();
		std::vector<std::string> chessboard(n, std::string(n, '.'));
		backtracking(n, 0, chessboard);
		return res;
	}
};
class Solution_lambda {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        auto isValid = [&](int row, int col) {
            // col
            for (int i = 0; i < row; ++i) 
                if (board[i][col] == 'Q')
                    return false;
            // main diagonal
            // for 循环里面的条件判断需要加 && ，不要逗号
            for (int i = row - 1, j = col - 1; i >= 0 && j>= 0; --i, --j) 
                if (board[i][j] == 'Q')
                    return false;
            // post diagonal
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
                if (board[i][j] == 'Q')
                    return false;
            return true;
        };
        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                res.push_back(board);
                return;
            }
            for (int col = 0; col < n; ++col)
                if (isValid(row, col)) {
                    board[row][col] = 'Q';
                    dfs(row + 1);
                    board[row][col] = '.';
                }
        };
        dfs(0);

        return res;
    }

};

int main() { return 0; }
