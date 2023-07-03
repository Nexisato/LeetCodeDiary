#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 思路：最外层开 公差 为基准的循环
 * 
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = -1;
        const int n = nums.size();
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        const int diff = *max_it - *min_it;
        // vector<vector<int>> dp(n + 1, vector<int>(diff, 1));
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i - 1; j >= 0; --j) {
        //         int delta = nums[i] - nums[j] + 500;
        //         dp[i + 1][delta] = dp[j + 1][delta] + 1;
        //     }
        // }
        // for (int i = 0; i < 1001; ++i)
        //     res = max(res, dp[n][i]);
        for (int d = -diff; d <= diff; ++d) {
            vector<int> dp(*max_it + 1, -1); // 以 nums[i] 结尾的最长等差数列长度
            for (int i = 0; i < n; ++i) {
                int prev = nums[i] - d;
                if (prev >= *min_it && prev <= *max_it && dp[prev] != -1) {
                    dp[nums[i]] = max(dp[nums[i]], dp[prev] + 1);
                    res = max(res, dp[nums[i]]);
                }

                dp[nums[i]] = max(dp[nums[i]], 1);
            }
        }
        return res;    
    }
};
int main() {
    vector<int> nums({20,1,15,3,10,5,8});
    Solution ss;

    int res = ss.longestArithSeqLength(nums);

    cout << res << endl;

    return 0;
}