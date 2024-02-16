/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0190-Reverse-Bits/190-Reverse-Bits.cpp
 * @Description: 
 */
/*
LeetCode: 190 Reverse Bits
Description:
Reverse bits of a given 32 bits unsigned integer.

Note:
Note that in some languages such as Java, there is no unsigned integer type. 
In this case, both input and output will be given as a signed integer type. 
They should not affect your implementation, as the integer's internal binary representation is the same, 
whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents 
the signed integer -1073741825.
Follow up:
If this function is called many times, how would you optimize it?
*/
#include <iostream>
using namespace std;
/*
思路：
1. 设定一个[31]次循环，原序列与 1 相与后，送入新建序列；然后令原序列右移，新建序列左移
2. 无循环，使用掩码将32位整数划分为具有较少位的块，分别将每个块反转，最后再合并，得到最终结果
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*uint32_t res = 0;
        for (int count = 0; count < 31; count++){
            res = res | (n & 1);
            res <<= 1;
            n >>= 1;
        }
        res |= (n & 1);
        return res;*/
        uint32_t res = 0, power = 31;
        while (n != 0) {
            res += (n & 1) << power;
            n >>= 1;
            power -= 1;
        }
        return res;
    }
    uint32_t reverseBits_mask(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main() {

    return 0;
}