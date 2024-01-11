/*
 * @Date: 2024-01-10 16:09:52
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0139_Word_Break/139.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> appear(wordDict.begin(), wordDict.end());
        const int n = s.length();
        bool dp[n + 1];  // DP 记录前 i 个字符是否可以被拆分
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            if (appear.count(s.substr(0, i))) {
                dp[i] = true;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (dp[j] && appear.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main() {


    return 0;
}