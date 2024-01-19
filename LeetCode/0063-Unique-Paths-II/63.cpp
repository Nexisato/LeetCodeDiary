/*
 * @Date: 2024-01-12 11:50:54
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0063_Unique_Paths_II/63.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 二维 DP 可以直接秒
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            if (obstacleGrid[0][i - 1] == 1) {
                break;
            }
            dp[1][i] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            if (obstacleGrid[i - 1][0] == 1) {
                break;
            }
            dp[i][1] = 1;
        }
        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
int main() {

    return 0;
}