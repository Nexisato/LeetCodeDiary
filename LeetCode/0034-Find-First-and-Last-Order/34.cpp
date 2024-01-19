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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res({-1, -1});
        int l = 0, r = n - 1;
        int mid = -1;
        //first
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
        //last
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
};
int main() {

    return 0;
}