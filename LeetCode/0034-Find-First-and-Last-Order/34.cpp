/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0034-Find-First-and-Last-Order/34.cpp
 * @Description:
 */
/*
LeetCode 34: Find First and Last Position of Element in Sorted Array
@Description:
Given an array of integers nums sorted in ascending order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 
Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：

*/
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> res({-1, -1});
        int l = 0, r = n - 1;
        int mid = -1;
        // first
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l >= n || nums[l] != target)
            l = -1;
        res[0] = l;
        l = 0, r = n - 1;
        // last
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (r < 0 || nums[r] != target)
            r = -1;
        res[1] = r;
        return res;
    }

    vector<int> searchRange_double_iter(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        const int n = nums.size();
        int lower = -1, higher = -1;
        int l = 0, r = n - 1;
        // 下边界
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                if (target == nums[mid])
                    lower = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // 上边界
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                if (target == nums[mid])
                    higher = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res[0] = lower;
        res[1] = higher;
        return res;
    }
};
int main() { return 0; }