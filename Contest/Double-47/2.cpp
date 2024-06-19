/*
LeetCode 5681: Check if Number is a Sum of Powers of Three
@Description:
Given an integer n, return true if it is possible to represent n as the sum of distinct
powers of three. Otherwise, return false. An integer y is a power of three if there
exists an integer x such that y == 3x.

Constraints:
1 <= n <= 10^7
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：3^14 < 10^7 && 3^15 > 10^7
用一个长度为15的数组存储小于10^7的所有3的幂
n倒序减这些3的幂看最终是否为0
*/
class Solution {
public:
	bool checkPowersOfThree(int n) {
		vector<int> table(15, 0);
		for (int i = 0; i < 15; ++i)
			table[i] = pow(3, i);
		for (int j = 14; j >= 0; --j) {
			if (table[j] <= n && n > 0)
				n -= table[j];
		}
		return (n == 0) ? true : false;
	}
};
int main() { return 0; }