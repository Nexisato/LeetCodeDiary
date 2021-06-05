/*
LeetCode 231: Power of 2
@Description:
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Constraints:
-2^31 <= n <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
n & (n - 1)可以将n的最低位1移除，因此可直接判断
注意：==的运算优先级高于 &，因此注意括号位置
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
int main() {

    return 0;
}