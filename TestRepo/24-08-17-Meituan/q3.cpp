#include <iostream>
#include <vector>
#include <array>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> prefixSum(n + 1, 0);
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, array<int, 2>({0, 0})));
    // dp[i][j][0] 表示这一连续子段中的最小和值
    // dp[i][j][1] 表示这一连续子段中的最大和值
    
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    
    for (int segment = 1; segment <= n; ++segment) {
        for (int l = 0; l + segment - 1 < n; ++l) {
            int r = l + segment - 1;
            if (segment = 1) {
                dp[l][r][0] = dp[l][r][1] = arr[l];
            } else {
                int delta_sum = prefixSum[r + 1] - prefixSum[l];
                dp[l][r][0] = min(min(dp[l][r - 1][0], dp[l + 1][r][0]), delta_sum);
                dp[l][r][1] = max(max(dp[l + 1][r][1], dp[l][r - 1][1]), delta_sum);
            }
        }
    }










    return 0;
}