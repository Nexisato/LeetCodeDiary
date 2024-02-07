/*
 * @Date: 2024-02-07 15:40:04
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0079-Word-Search/79.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 思路：DFS回溯搜索
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<bool(int, int, int)> dfs = [&](int x, int y, int idx) {
            if (idx == word.size())
                return true;
            if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] ||
                board[x][y] != word[idx])
                return false;
            visited[x][y] = true;
            if (dfs(x + 1, y, idx + 1) || dfs(x - 1, y, idx + 1) ||
                dfs(x, y + 1, idx + 1) || dfs(x, y - 1, idx + 1))
                return true;
            visited[x][y] = false;
            return false;
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0))
                    return true;
        return false;
    }
};
int main() { return 0; }