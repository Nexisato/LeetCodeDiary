/*
LeetCode 153: Find Minimum in Rotated Sorted Array
@Description:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the 
array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

Constraints:
n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：我摊牌了，我直接遍历
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid = 0;
        int res = nums[0];
        while (low <= high) {
            mid = (low + high) / 2;
            //[0, mid]有序
            if (nums[0] <= nums[mid]) {
                
            }
            else {

            }
        }
        return res;
    }
};
int main() {

    return 0;
}