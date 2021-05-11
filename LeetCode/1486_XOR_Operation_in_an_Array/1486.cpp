/*
LeetCode 1486: XOR Operation in an Array
@Description:
Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.

Constraints:
1 <= n <= 1000
0 <= start <= 1000
n == nums.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：zz题
*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res ^= (start + i * 2);
        return res;
    }
};
int main() {

    return 0;
}