#include <iostream>
#include <vector>
#include <string>
using namespace std;


// dp[i] 表示 0~i 有效的括号数量，一定是偶数
// s[i - dp[i - 1] - 1]，这个位置跳过了有效的括号数量，应当与 s[i] 相对应
// 补充完括号后，再考虑前面一个位置的有效括号数量
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.length();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main() {


    return 0;
}