// LeetCode 10 变体：典型 DP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match(const string& text, const string& pattern) {
    int m = text.size();
    int n = pattern.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // 空文本和空模式是匹配的
    dp[0][0] = true;

    // 处理空文本和非空模式的情况
    for (int j = 1; j <= n; ++j) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // 填充 dp 数组
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pattern[j - 1] == '.' || pattern[j - 1] == text[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || // 匹配零个字符
                           ((pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) && dp[i - 1][j]); // 匹配一个或多个字符
            } else if (pattern[j - 1] == '?') {
                dp[i][j] = (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) && dp[i - 1][j - 2] || // 匹配一个字符
                           (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) && dp[i - 1][j - 1]; // 匹配多个字符
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text = "aaa";
    string pattern = "aa*";
    if (match(text, pattern)) {
        cout << "Match!" << endl;
    } else {
        cout << "No match!" << endl;
    }
    return 0;
}