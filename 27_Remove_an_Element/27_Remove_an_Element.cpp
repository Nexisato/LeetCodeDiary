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
#include<bits/stdc++.h>
using namespace std;
/*
思路：
如何不按照顺序移除元素？
双指针yyds
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

int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution ss;
    cout << ss.removeElement(nums, val) << endl;
    return 0;
}