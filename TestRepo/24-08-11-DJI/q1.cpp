/**
在一个m*n的二维网格中，我们的无人机从左上角出发去到右下角。
无人机初始电量是一个正整数，如果电量降低到0或以下，那么会立即炸机坠毁。
路上经过的所有网格有不同的物理特性，导致无人机经过时消耗的电量不一样（负整数代表消耗的电量值）；
有些网格如此奇妙，对于无人机来说如同瞬间通过不消耗电量（网格数值为0）；
还有一些网格无人机经过会增加电量（正整数代表增加的电量）；

为了尽快到达右下角，无人机每次只向右或向下移动一步。
请编程计算并返回能够确保无人机到达右下角的最低初始电量。

思路：经典迷宫网格 DP
逆推
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <climits>  

using namespace std;

class Solution {
public:
// dp[i][j] 表示从 i, j 出发到终点的最小电量值
/* Write Code Here */
int calcMinimumPower(vector < vector < int > > grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    dp[m-1][n-1] = max(1, 1 - grid[m-1][n-1]);

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i < m - 1) {
                dp[i][j] = min(dp[i][j], max(1, dp[i + 1][j] - grid[i][j]));
            }
            if (j < n - 1) {
                dp[i][j] = min(dp[i][j], max(1, dp[i][j + 1] - grid[i][j]));
            }
        }
    }

    return dp[0][0];
}
};
int main() {
    int res;

    int grid_rows = 0;
    int grid_cols = 0;
    cin >> grid_rows >> grid_cols;
    vector< vector < int > > grid(grid_rows);
    for(int grid_i=0; grid_i<grid_rows; grid_i++) {
        for(int grid_j=0; grid_j<grid_cols; grid_j++) {
            int grid_tmp;
            cin >> grid_tmp;
            grid[grid_i].push_back(grid_tmp);
        }
    }
    Solution *s = new Solution();
    res = s->calcMinimumPower(grid);
    cout << res << endl;

    return 0;

}