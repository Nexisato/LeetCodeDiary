/*
LeetCode 342: Power of 4
@Description:
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Constraints:
-2^31 <= n <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
n = 4^x = 2 ^(2*x) = 2^x * 2^x
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        int m = sqrt(n);
        return (m * m == n) && (m & (m - 1)) == 0;
    }
};
int main() {

    return 0;
}