/*
LeetCode 485: Max Consecutive Ones
@Description:
Given a binary array, find the maximum number of consecutive 1s in this array.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, record = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                ++record;
            else 
                record = 0;
            res = max(res, record);
        }
        return res;
    }
};
int main() {

    return 0;
}