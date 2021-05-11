/*
LeetCode 220: Contains Duplicate III
@Description:
Given an integer array nums and two integers k and t, return true if there 
are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

Constraints:
0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口 + 有序集合
1. 对于数组中的某个元素x，其左侧k个元素，若有一个元素落在区间[x - t, x + t]中，
我们就找到了一对符合条件的元素

2. 利用set快速crud元素。对于元素x，当我们希望判断滑动窗口中是否存在某个数y落在区间[x - t, x + t]中，
只需要判断滑动窗口中所有大于等于x - t的元素中最小元素是否小于等于x + t即可
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> appear;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto iter = appear.lower_bound(max(nums[i], INT32_MIN + t) - t);
            if (iter != appear.end() && *iter <= min(nums[i], INT32_MAX - t) + t)
                return true;
            appear.insert(nums[i]);
            if (i >= k)
                appear.erase(nums[i - k]);
        }
        return false;
    }
};
int main() {


    return 0;
}