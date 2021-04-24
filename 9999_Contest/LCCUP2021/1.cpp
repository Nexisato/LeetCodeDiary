/*
LeetCode 
@Description:
小力将 N 个零件的报价存于数组 nums。小力预算为 target，假定小力仅购买两个零件，要求购买零件的花费不超过预算，
请问他有多少种采购方案。

注意：答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：典型的双指针
要累计区间和
*/
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        int n = nums.size();
        long long res = 0;
        const int MODE = pow(10, 9) + 7;
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while (l < n - 1) {
            int lNum = nums[l];
            int count1  = 0, count2 = 0;
            r = l + 1;
            while (r < n && nums[l] + nums[r] <= target) {
                count1++;
                r++;
            }
            count2 = count1;
            l++;
            while (nums[l] == lNum) {
                l++;
                count2--;
            }
            res += (count2 + count1) * (count1 - count2 + 1) / 2;
        }
        return res % MODE;
    }
};
int main() {
    vector<int> nums = {2, 2, 1, 9};
    int target = 10;
    Solution ss;
    cout << ss.purchasePlans(nums, target) << endl;
    return 0;
}