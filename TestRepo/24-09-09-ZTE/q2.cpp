// 本题 DFS 会超时，请换用 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 骑士的8种可能移动方式
vector<pair<int, int>> moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// 检查坐标是否在棋盘内
bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int minKnightMoves(int n, int startRow, int startCol, int endRow, int endCol) {
    if (startRow == endRow && startCol == endCol) {
        return 0;
    }

    // x, y, step
    queue<tuple<int, int, int>> q;
    q.push({startRow, startCol, 0});

    vector<vector<uint8_t>> visited(n, vector<uint8_t>(n, 0));
    visited[startRow][startCol] = 1;

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        for (auto [dx, dy] : moves) {
            int newX = x + dx;
            int newY = y + dy;

            
            if (newX == endRow && newY == endCol) {
                return steps + 1;
            }
       
            if (isValid(newX, newY, n) && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                q.push({newX, newY, steps + 1});
            }
        }
    }

    // 如果无法到达终点，返回-1
    return -1;
}

int main() {
    int n = 8; // 棋盘大小
    int startRow = 0, startCol = 0; // 起点
    int endRow = 7, endCol = 0; // 终点

    int result = minKnightMoves(n, startRow, startCol, endRow, endCol);
    cout << "Minimum steps: " << result << endl;

    return 0;
}