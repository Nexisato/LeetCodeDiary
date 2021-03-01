/*
LeetCode : 191 Number of 1 Bits
Description:
Write a function that takes an unsigned integer and returns the number of '1' bits 
it has (also known as the Hamming weight).

Note:
Note that in some languages such as Java, there is no unsigned integer type. 
In this case, the input will be given as a signed integer type. It should not affect your implementation, 
as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 3 above, the input represents the signed integer. -3.
Follow up: If this function is called many times, how would you optimize it?

Constraints:
The input must be a binary string of length 32
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. n 分别与 1 相与，再不断右移位，进行计数
2. n 与 n-1 相与，消除 n 中最右侧的 1，若不为 0，则更新 n 后，继续与 n-1 相与，直到 n 为 0
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
    int hammingWeight_opt(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};

int main() {

    return 0;
}