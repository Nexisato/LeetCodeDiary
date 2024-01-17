/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0122_买卖股票的最佳时机/122_买卖股票的最佳时机.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
            result += max(0, prices[i] - prices[i - 1]);

        return result;
    }
    int maxProfit_dp(vector<int> &prices) {
        const int n = prices.size();
        // 多一个状态，记录手里有无股票
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            // 卖票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 买票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution ss;
    cout << ss.maxProfit(prices);
    /*for(vector<int>::iterator it=prices.begin();it<prices.end();it++)
        cout<<*(it)<<endl;*/
    return 0;
}