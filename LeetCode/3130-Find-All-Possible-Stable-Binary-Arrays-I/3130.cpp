// 同 3129
#include <array>
#include <vector>
using namespace std;

// 三维DP + 容斥原理
// 考虑最后一个位置填 0 还是 1
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MODULO = 1e9 + 7;
        vector<vector<array<int, 2>>> dp(zero + 1, vector<array<int, 2>>(one + 1));
        for (int i = 1; i <= min(zero, limit); ++i) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp[0][j][1] = 1;
        for (int i = 1; i <= zero; ++i)
            for (int j = 1; j <= one; ++j) {
                int prev_zero = i - 1 - limit;
                int prev_one = j - 1 - limit;

                dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % MODULO;
                if (prev_zero >= 0) 
                    dp[i][j][0] = (MODULO + dp[i][j][0] - dp[prev_zero][j][1]) % MODULO;

                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MODULO;
                if (prev_one >= 0)
                    dp[i][j][1] = (MODULO + dp[i][j][1] - dp[i][prev_one][0]) % MODULO;
            }

        return (dp[zero][one][0] + dp[zero][one][1]) % MODULO;
    }
};
int main() { return 0; }