#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxScore(vector<int>& a) {
    int n = a.size();
    // dp[i][j] 表示从 [i, j] 能够打靶得到的最高分，
    // max(dp[i][k - 1] + dp[k + 1][j] + a[i - 1] * a[j + 1] * a[k])
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // 在数组 a 的两侧添加虚拟靶，分数为 1
    a.insert(a.begin(), 1);
    a.push_back(1);

    // 枚举区间长度
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                             a[i - 1] * a[j + 1] * a[k]);
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> a = {2, 1, 3};
    int result = maxScore(a);
    cout << "Maximum score: " << result << endl;
    return 0;
}