/*
LeetCode 33: Search in Rotated Sorted Array
@Description:

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot 
index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., 
nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] 
might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
 
Follow up: Can you achieve this in O(log n) time complexity?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分查找
1. 由于该数组是局部有序的，可以发现：将数组从中间分开成左右两部分的时候，一定有一部分数组有序
2. 若[low, mid]是有序数组，且targe在[nums[low], nums[mid]]区间内，则搜索范围缩小到[l, mid - 1]
否则搜索[mid + 1, high]

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int low = 0, high = n - 1, mid = (low + high) / 2;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            /*分区间讨论*/
            //[0,mid]有序
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            //[0, mid]无序
            else {
                if (nums[mid] < target && target <= nums[n - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
int main() {

    return 0;
}