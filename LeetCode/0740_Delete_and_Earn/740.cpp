/*
LeetCode 740: Delete and Earn
@Description:
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：将等于x的所有数全部加起来，构成sum[]数组
对于sum[]数组，可以依赖于打家劫舍的思路进行解决
*/
class Solution {
private:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> table;
        for (auto& num : nums)
            table[num]++;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxVal + 1);
        for (auto [k, v] : table)
            sum[k] = k * v;
        return rob(sum);
    }
};
int main() {


    return 0;
}