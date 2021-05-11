/*
LeetCode 303: Range Sum Query Immutable Matrix
@Description:
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Implement the NumArray class:
NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] 
inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j]))

Constraints:
0 <= nums.length <= 10^4
-10^5 <= nums[i] <= 10^5
0 <= i <= j < nums.length
At most 10^4 calls will be made to sumRange.。
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：前缀和
1. 朴素的想法是循环累加nums[i]~nums[j]，然而由于会进行多次检索，因此为了降低检索的总时间应当降低时间复杂度
2. 构造前缀和数组sums[i]，表示从nums[0]~nums[i - 1]的累加和
*/
class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
int main() {

    return 0;
}