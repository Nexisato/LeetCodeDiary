/*
Description:
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/
#include<bits/stdc++.h>
using namespace std;

/*
思路：二分查找，边界点用条件判断分别处理
分为四种情况：
1. 目标值在所有元素之前
2. 目标值待插入数组
3. 目标值等于数组中某个元素的值
4. 目标值在所有元素之后
*/
/*
Result:
Time Complexity: O(logn) 
Space Complexity: O(1)
*/
class Solution {
private:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target >= nums[mid] && target <= nums[mid+1]) return mid + 1;
        else if (nums[mid] <= target) return binarySearch(nums, mid + 1, high, target);
        else return binarySearch(nums, low, mid - 1, target);
        return -1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (target <= nums[low]) return 0;
        else if (target > nums[high]) return high + 1;
        return binarySearch(nums, low, high, target);
    }
};

int main (){
    vector<int> nums = {1, 3};
    int target = 3;
    Solution ss;
    cout << ss.searchInsert(nums, target) << endl;
    return 0;
}