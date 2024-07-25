#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

// 这里需要使用到一个状态机转移的思路

const int MAX_COUNT = 20001;
const int INF = 1e+6;


// not completed
int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    int max_val = - 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        max_val = std::max(max_val, nums[i]);
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(max_val + 1, INT_MAX));
    dp[0][nums[0]] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= max_val; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (k <= j) {
                    // 计算操作次数
                    int operations = INT_MAX;
                    if (j == nums[i]) {
                        operations = 0;
                    } else if (j == 2 * nums[i]) {
                        operations = 1;
                    } else if (j == nums[i] / 2) {
                        operations = 1;
                    } else {
                        continue;
                    }

                    if (dp[i-1][k] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[i-1][k] + operations);
                    }
                }
            }
        }
    }

    // 找到最小的操作次数
    int result = INT_MAX;
    for (int j = 0; j <= max_val; ++j) {
        result = std::min(result, dp[n-1][j]);
    }
    
    std::cout << result << std::endl;
    







    return 0;
}