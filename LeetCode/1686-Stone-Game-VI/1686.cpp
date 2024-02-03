/*
 * @Date: 2024-02-02 09:55:50
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/1686-Stone-Game-IV/1686.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 思路：博弈论
// 1. 两个人都是最优策略
// 2. A 抽走这块石头之后，B 就没法拿了
// 3. A 试图 最大化 A - B，B 试图 最小化 A - B
class Solution {
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
        const int n = aliceValues.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        // 按照 aliceValues[i] + bobValues[i] 从大到小排序 降序  
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                res += aliceValues[idx[i]];
            } else {
                res -= bobValues[idx[i]];
            }
        }
        if (res > 0) {
            return 1;
        } else if (res < 0) {
            return -1;
        }

        return 0;
    }
};
int main() { return 0; }