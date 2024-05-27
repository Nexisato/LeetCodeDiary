#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/***
 * mean | sumTotal
 * (n + m) | sumTotal
 */
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumTotal = mean * (m + n);
        int sumRolls = accumulate(rolls.begin(), rolls.end(), 0);
        int sumMissing = sumTotal - sumRolls;

        if (sumMissing < n || sumMissing > 6 * n) {
            return {};
        }

        vector<int> res(n, 0);

        // 根据余数和商的关系，计算每个数的值
        int base = sumMissing / n;
        int remain = sumMissing % n;

        for (int i = 0; i < n; i++) {
            res[i] = base + (i < remain ? 1 : 0);
        }

        return res;
    }
};

int main() { return 0; }