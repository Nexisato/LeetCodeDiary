#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 记忆化搜索
 * dp[i][j][p] 将 stones[i] 到 stones[j] 合并成 p 堆的最小成本 
 * 
 */
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        const int n = stones.size();
        if ((n - 1) % (k - 1))
            return -1;
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // 前缀和

        int dp[n][n];
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = INT32_MAX;
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);    
                }
                if ((j - i) % (k - 1) == 0)
                    dp[i][j] += s[j + 1] - s[i];
                
            }
        }
        return dp[0][n - 1];

        // int memo[n][n][k + 1];
        // memset(memo, -1, sizeof(memo)); // -1 表示还没有计算过

        // function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
        //     int &res = memo[i][j][p]; // 注意这里是引用，下面会直接修改 memo[i][j][p]
        //     if (res != -1) return res;
        //     if (p == 1) // 合并成一堆
        //         return res = i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
        //     res = INT_MAX;
        //     for (int m = i; m < j; m += k - 1) // 枚举哪些石头堆合并成第一堆
        //         res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
        //     return res;
        // };
        // return dfs(0, n - 1, 1);

        // int memo[n][n];
        // memset(memo, -1, sizeof(memo));

        // function<int (int, int)> dp = [&](int i, int j) -> int {
        //     int &res = memo[i][j];
        //     if (res != -1) return res;
        //     if (i == j) return 0;
        //     res = INT32_MAX;
        //     for (int m = i; m < j; m += k - 1) {
        //         res = min(res, dp(i, m) + dp(m + 1, j));
        //     }
        //     if ((j - i) % (k - 1) == 0)
        //         res += s[j + 1] - s[i];
        //     return res;
        // };

        // return dp(0, n - 1);

    }
};
int main() {

    return 0;
}