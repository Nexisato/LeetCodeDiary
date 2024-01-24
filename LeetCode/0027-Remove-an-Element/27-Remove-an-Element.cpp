/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0027-Remove-an-Element/27-Remove-an-Element.cpp
 * @Description: 
 */
/*
Description:
Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this 
by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Clarification:
Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, 
which means a modification to the input array will be known to the caller as well.

Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/
#include<iostream>
#include<vector>
using namespace std;
/*
思路：
如何不按照顺序移除元素？
双指针yyds
有通向 和 相向 两种方向
相向的话，注意左边是寻找第一个等于的，右边是寻找第一个不等于的
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastPtr = 0, slowPtr = 0;
        for (;fastPtr < nums.size(); fastPtr++) 
            if (nums[fastPtr] != val)
                nums[slowPtr++] = nums[fastPtr];
        return slowPtr;
    }
};
/*
这种方法会使得 elements order 被改变
*/
class Solution_oppsite {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            while (left <= right && nums[left] != val) ++left;
            while (left <= right && nums[right] == val) --right;
            if (left < right)
                nums[left++] = nums[right--];
        }
        return left;
    }
};


int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution ss;
    cout << ss.removeElement(nums, val) << endl;
    return 0;
}