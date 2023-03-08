#include <bits/stdc++.h>
using namespace std;

/* 
构建二维数组DP，送分
可以进一步优化空间复杂度

*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[0][0] = grid[0][0];
        // for (int i = 1; i <= m; i ++) {
        //     for (int j = 1; j <= n; j++) {
        //         dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
        //     }
        // }
        // return dp[m][n];
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            int row = i %  2;
            for (int j = 1; j <= n; j ++) {
                dp[row][j] = grid[i - 1][j - 1] + max(dp[row][j - 1], dp[1 - row][j]);
            }
        }
        return dp[m % 2][n];
    }
};
int main() {


    return 0;
}