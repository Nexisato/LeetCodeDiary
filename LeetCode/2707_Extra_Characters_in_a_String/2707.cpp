/*
 * @Date: 2024-01-09 14:18:36
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2707_Extra_Characters_in_a_String/2707.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
using namespace std;



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> appear(dictionary.begin(), dictionary.end());    // 记录出现过的单词
        const int n = s.length();
        int dp[n + 1];  //DP 记录前 i 个字符最少需要添加几个字符
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            // 第 i 个字符相比于 i - 1 多要添加一个字符
            // 若 s[j, i) 出现过，则 dp[i] = min(dp[j], dp[i])  (j < i) 
            for (int j = 0; j < i; ++j) {
                if (appear.count(s.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};
int main() {
    string s = "leetscode";
    Solution *ss;
    vector<string> dictionary = {"leet","code"};
    cout << ss->minExtraChar(s, dictionary) << endl;


    return 0;
}