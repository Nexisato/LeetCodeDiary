#include <iostream>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

/**
 * 思路：可以按照满二叉树进行二进制拆解，也可以数位DP
 */
class Solution {
public:
    int findIntegers(int n) {
        // dp[i] 表示长度为 i 的二进制数中不包含连续的 1 的个数
        vector<int> dp(31);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 31; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int pre = 0, res = 0;
        for (int i = 29; i >= 0; --i) {
            int val = 1 << i;
            if ((n & val) != 0) {
                res += dp[i];
                if (pre == 1) {
                    break;
                }
                pre = 1;
            } else {
                pre = 0;
            }

            if (i == 0) {
                ++res;
            }
        }

        return res;
    }
};





int main() {



    return 0;
}