/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0053-Maximum-Sub-Array/53-Maximum-Sub-Array.cpp
 * @Description: 
 */
/*
LeetCode 53: Maximum Subarray
Description:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.

Constraints:
1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：
1. 动态规划
- 建立数组 sub[i]，表示以 ith 元素作为结尾的子序列最大和
DP范式：sub[i] = max(sub[i-1] + nums[i], nums[i])
2. 分治
定义一个操作 get(a,l,r)，表示查询a序列[l, r]区间内的最大子段和
取 m = (l + r) / 2
对于一个区间 [l,r]，可维护以下4个信息
-lSum [l,r]内以l为左端点的最大子段和
-rSum [l,r]内以r为右端点的最大子段和
-mSum [l,r]内的最大子段和
-iSum [l,r]的区间和
对于长度大于1的区间：
--iSum为 左子区间 的 iSum 加上 右子区间 的 iSum
--lSum存在两种可能：
    · 左子区间的 lSum
    · 左子区间的 iSum 加上 右子区间的 lSum
--rSum存在两种可能：
    · 右子区间的 rSum
    · 右子区间的 iSum 加上 左子区间的 rSum
mSum考虑如下几种情况：
    若不跨越 m：
        mSum 可能为左子区间的 mSum 或 右子区间的 mSum
    若跨越 m：
        左子区间的 rSum 和 右子区间的 lSum 之和
*/
class Solution {
public:
    /*
    DP:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        vector<int> sub(nums.size());
        sub[0] = nums[0];
        res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sub[i] = max(sub[i-1] + nums[i], nums[i]);
            res = max(sub[i], res);
        }
        return res;
    }
    */

    struct Status {
        int lSum, rSum, mSum, iSum;
    };
    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(l.rSum + r.iSum, r.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status){lSum, rSum, mSum, iSum};
    }
    Status get(vector<int>& a, int l, int r) {
        if(l==r) {
            return (Status){a[l],a[l],a[l],a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
    
};
int main() {
    Solution ss;
    vector<int> nums = {-1, 0, -2};
    cout << ss.maxSubArray(nums) << endl;
    return 0;
}