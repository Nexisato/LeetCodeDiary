/*
LeetCode 1482: Minimum Number of Days to Make m Bonquets
@Description:
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1.

Constraints:
bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：m * k <= n
1. 增加一个check函数，用于计算 长度为k 且 最大元素不超过days 的 不重合的 连续子数组的 数量
    辅助参数除了bloomDay、m、k之外，还有一个参数days指定天数，
2. days很小的时候，辅助函数总是返回false；很大的时候，总是返回true，因此可以认为辅助函数关于days递增
因此，我们可以通过二分查找确认这个days的最小值
*/
class Solution {
private:
    bool check(vector<int>& bloomDay, int m, int k, int days) {
        int bonquets = 0;
        int flowers = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= days) {
                ++flowers;
                if (flowers == k) {
                    ++bonquets;
                    flowers = 0;
                }
            }
            else
                flowers = 0;
        }
        return bonquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int days = low + (high - low) >> 1;
            if (check(bloomDay, m, k, days))
                high = days;
            else
                low = days + 1;
        }
        return low;
    }
};
int main() {

    return 0;
}