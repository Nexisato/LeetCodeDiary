/*
 * @Date: 2024-01-15 11:56:43
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0045_Jump_Game_II/45.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

// DP 和贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1e+4);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
int main() {

    return 0;
}