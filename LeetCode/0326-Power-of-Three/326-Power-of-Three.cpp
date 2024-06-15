/*
LeetCode: 326 Power of Three
Description:
Given an integer of n, return true if it's a power of three. Otherwise return false
An integer of n is a power of three, if there exists an integer x such that n == 3^x.

Constraints:
-2^31 <= n <= 2^31 - 1

Follow Up:
Could you do it without using loop/recursion method?
*/
#include <bits/stdc++.h>
using namespace std;

/*
思路：
0. n <= 0 时，直接返回false，否则再遍历浪费时间
1. 常规解法，n 迭代除以 3 ，看最后结果是否为 1
2. 换底，看幂是否为整数
3. int类型变量为4个字节，整数最大值为 2^31 - 1，则在此范围内3的幂最大值为 3^floor(log3(INT32_MAX))=1162261467
*/
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		while (n % 3 == 0)
			n /= 3;
		return (n == 1) ? true : false;
	}
	bool isPowerOfThree_2(int n) {
		if (n <= 0)
			return false;
		double p = log10(n) / log10(3);
		return (p == floor(p)) ? true : false;
	}
	bool isPowerOfThree_3(int n) { return (n > 0) && (1162261467 % n == 0); }
};
int main() { return 0; }