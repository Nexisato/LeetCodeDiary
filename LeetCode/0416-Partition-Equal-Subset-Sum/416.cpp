#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;


// 0-1 背包问题
// 前 n 个数能否凑成和为 target
// 状态转移方程： dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};
int main() {
    vector<int> nums = {1, 2, 5};
    Solution* ss = new Solution();

    bool res = ss->canPartition(nums);
    cout << res << endl;


    return 0;
}