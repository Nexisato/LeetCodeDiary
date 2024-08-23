#include <iostream>
#include <vector>
#include <functional>
using namespace std;



class Solution {
private:
    int dir[4][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        const int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int total = 0, rotted = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) 
                    ++total;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                    ++rotted;
                }
                
            }
        }
        if (total == 0) return res;
        while (!q.empty() && total > 0) {
            ++res;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        --total;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return (total > 0) ? -1 : res;
    }
};

int main() {



    return 0;
}