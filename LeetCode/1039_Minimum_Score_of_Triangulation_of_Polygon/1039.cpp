#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * break down 为子问题
 * dp(i, j) 表示两个顶点，他们构成三角形的最小顶点乘积和
 * 
 */

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        unordered_map<int, int> memo;
        function <int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) return 0;
            if (i + 2 == j) return values[i] * values[i + 1] * values[j];

            int key = i * n + j; // to avoid traversaling repeatedly
            if (!memo.count(key)) {
                int product = INT32_MAX;
                for (int k = i + 1; k < j; ++k)
                    product = min(product, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                memo[key] = product;
            }
            return memo[key];
        };
        return dp(0, n - 1);

    }
};

int main() {

    return 0;
}