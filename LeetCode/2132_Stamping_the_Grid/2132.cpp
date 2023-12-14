#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 思路：必须把邮票贴满
 *
 *
 */
class Solution {
public:
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight,
                         int stampWidth) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                prefixSum[row + 1][col + 1] =
                    prefixSum[row][col + 1] + prefixSum[row + 1][col] -
                    prefixSum[row][col] + grid[row][col];
            }
        }
        // 贴邮票
        // 二维差分数组相当于多减掉了1次
        for (int x1 = 1; x1 + stampHeight - 1 <= m; ++x1) {
            for (int y1 = 1; y1 + stampWidth - 1 <= n; ++y1) {
                int x2 = x1 + stampHeight - 1, y2 = y1 + stampWidth - 1;
                int sum = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] -
                          prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
                // diff 记录的是每个位置被覆盖的次数
                if (sum == 0) {
                    ++diff[x1][y1];
                    --diff[x2 + 1][y1];
                    --diff[x1][y2 + 1];
                    ++diff[x2 + 1][y2 + 1];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i + 1][j + 1] +=
                    diff[i][j + 1] + diff[i + 1][j] - diff[i][j];
                if (diff[i + 1][j + 1] == 0 && grid[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution *ss;
    vector<vector<int>> grid({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
    cout << ss->possibleToStamp(grid, 1, 1) << endl;
    return 0;
}