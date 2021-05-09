/*
LeetCode 1473: Paint House III
@Description:
There is a row of m houses in a small city, each house must be painted with 
one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:
- houses[i]: is the color of the house i, and 0 if the house is not painted yet.
- cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. 
If it is not possible, return -1.

Constraints:
m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：三维DP(略凶残)
dp[i][j][k]：表示前i个房子组成的j个街区，且第i个房子颜色为k，此时的最小花费
- 转移方程：
    - 当前房子有颜色， 无需粉刷，cost不变：
        第i - 1个房子和第i个房子颜色不相同，形成新的街区
        第i - 1个房子和第i个房子颜色相同，街区数量不变
        cur_color = , prev_color[1...n]
            dp[i][j][cur_color] = min(dp[i - 1][j - 1][prev_color], prev_color != cur_color
                                      dp[i - 1][j][cur_color]       prev_color == cur_color
                                      )
    - 当前房子无颜色：
        dp[i][j][cur_color] = costs[i][cur_color] + min(dp[i - 1][j - 1][prev_color]
                                                        dp[i - 1][j][cur_color])
*/
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[m][target + 1][n + 1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));

        //初始化
        if (houses[0] == 0) {
            for (int k = 1; k <= n; ++k)
                dp[0][1][k] = cost[0][k - 1];
        }
        else
            dp[0][1][houses[0]] = 0;

        //状态转移
        for (int i = 1; i < m; ++i) {
            //当前房子无颜色
            if (houses[i] == 0) {
                for (int cur_color = 1; cur_color <= n; ++cur_color)
                    for (int prev_color = 1; prev_color <= n; ++prev_color)
                        for (int j = 1; j <= target; ++j) {
                            if (cur_color == prev_color)
                                dp[i][j][cur_color] = min(dp[i][j][cur_color], 
                                                    cost[i][cur_color - 1] + dp[i - 1][j][cur_color]);
                            else
                                dp[i][j][cur_color] = min(dp[i][j][cur_color],
                                                    cost[i][cur_color - 1] + dp[i - 1][j - 1][prev_color]);
                        }
            }
            //当前房子有颜色
            else {
                int cur_color = houses[i];
                for (int prev_color = 1; prev_color <= n; ++prev_color)
                    for (int j = 1; j <= target; ++j) {
                        if (cur_color == prev_color)
                            dp[i][j][cur_color] = min(dp[i][j][cur_color], 
                                                    dp[i - 1][j][cur_color]);
                        else
                            dp[i][j][cur_color] = min(dp[i][j][cur_color],
                                                    dp[i - 1][j - 1][prev_color]);
                    }
            }
        }
        
        int res = *min_element(dp[m - 1][target], dp[m - 1][target] + n + 1);
        return (res == 0x3f3f3f3f) ? -1 : res;
    }
};
int main() {
    vector<int> houses(5, 0);
    vector<vector<int>> cost(5, vector<int>(2));
    cost[0][0] = 1; cost[0][1] = 10;
    cost[1][0] = 10; cost[1][1] = 1;
    cost[2][0] = 10; cost[2][1] = 1;
    cost[3][0] = 1; cost[3][1] = 10;
    cost[4][0] = 5; cost[4][1] = 1;
    int target = 3;
    Solution ss;
    int res = ss.minCost(houses, cost, 5, 2, 3);
    cout << res << endl;
    return 0;
}