/*
 * @Date: 2024-02-23 10:05:17
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0062-Unique-Paths/62.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            dp[i][1] = 1;
        }
        for (int i = 2; i <= m; ++i)
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m][n];
    }
};
int main() {

    return 0;
}