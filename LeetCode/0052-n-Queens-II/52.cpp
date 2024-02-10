/*
 * @Date: 2024-02-10 15:18:15
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0052-n-Queens-II/52.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
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
                ++res;
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