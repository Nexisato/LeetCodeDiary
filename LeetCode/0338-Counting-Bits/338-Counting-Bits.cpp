/*
LeetCode 338: Counting Bits
@Description:
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
calculate the number of 1's in their binary representation and return them as an array.

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function
like __builtin_popcount in c++ or in any other language.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：对每个 <=num的数字进行计数（暴力法，时间复杂度较高）
【动态规划】——最高有效位
对于正整数x，找到小于等于x的最大整数次幂y，只有最高次为1，其余位次均为0，且该位次为x的最高 1bit 位
因此，令 z = x - y，则有 bits[x] = bits[z] + 1
判断一个数y是否是2的次幂的方法：y&(y-1) == 0
*/
class Solution {
public:
	vector<int> countBits(int num) {
		if (num == 0)
			return {0};
		vector<int> res(num + 1, 0);
		int maxBit = 0;
		for (int i = 1; i <= num; ++i) {
			if ((i & (i - 1)) == 0)
				maxBit = i;
			res[i] = res[i - maxBit] + 1;
		}
		return res;
	}
};
/*
【动态规划】——最低有效位
*/
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			res[i] = res[i >> 1] + (i & 1);
		return res;
	}
};
int main() { return 0; }