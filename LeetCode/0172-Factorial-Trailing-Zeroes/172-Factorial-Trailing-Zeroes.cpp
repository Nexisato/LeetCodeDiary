/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0172-Factorial-Trailing-Zeroes/172-Factorial-Trailing-Zeroes.cpp
 * @Description:
 */
/*
LeetCode 172: Factorial Trailing Zeros
@Description:
Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

Constraints:
0 <= n <= 10^4
*/
#include <iostream>
using namespace std;
/*
思路：素因数分解
求出小于等于n的所有数的 质因数分解中5的幂指数 之和
*/
class Solution {
public:
	int trailingZeroes(int n) {
		int count = 0;
		int num = 5;
		;
		while (num <= n) {
			int temp = num;
			while (temp % 5 == false) {
				count++;
				temp /= 5;
			}
			num += 5;
		}
		return count;
	}
};
int main() { return 0; }