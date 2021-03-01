/*
LeetCode 448: Find All Numbers Disappear in Array
@Description:
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：原地修改法
遍历原数组，将出现的num对应nums的下标，对应值加上n

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto &num : nums) {
            int tmp = (num - 1) % n;
            nums[tmp] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n)
                res.emplace_back(i + 1);
        }
        return res;
    }
};
int main() {

    return 0;
}