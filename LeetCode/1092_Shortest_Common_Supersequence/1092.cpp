#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        string res = "";
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  //dp[i][j] 表示 str1[0-i] 同 str2[0-j] 的最长公共序列长度
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // 上述过程的逆推
        int i = m, j = n;
        while ( (i != 0) || (j != 0)) {
            if (i == 0) res += str2[--j];
            else if (j == 0) res += str1[--i];
            else {
                if (dp[i][j] == dp[i - 1][j]) // str1 多余，要包裹住
                    res += str1[--i];
                else if (dp[i][j] == dp[i][j - 1])
                    res += str2[--j];
                else {
                    res += str1[--i];
                    --j;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {


    return 0;
}