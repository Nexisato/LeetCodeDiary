#include <array>
#include <iostream>
#include <vector>
using namespace std;

// dp[step][x][y] = \sum 1/8 * dp[step - 1][nx][ny]
class Solution {
private:
    int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                     {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    bool is_valid(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(
            k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        for (int step = 0; step <= k; ++step) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (step == 0)
                        dp[step][i][j] = 1.0;
                    else {
                        for (int _i = 0; _i < 8; ++_i) {
                            int nx = i + dir[_i][0], ny = j + dir[_i][1];
                            if (!is_valid(nx, ny, n)) continue;
                            dp[step][i][j] += (dp[step - 1][nx][ny] / 8);
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};

int main() { return 0; }