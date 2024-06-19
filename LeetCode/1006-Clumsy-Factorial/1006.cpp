/*
LeetCode 1006: Clumsy Factorial
@Description:
Normally, the factorial of a positive integer n is the product of all positive integers
less than or equal to n.  For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 *
2 * 1.

We instead make a clumsy factorial: using the integers in decreasing order, we swap out
the multiply operations for a fixed rotation of operations: multiply (*), divide (/),
add (+) and subtract (-) in this order.

For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However, these
operations are still applied using the usual order of operations of arithmetic: we do
all multiplication and division steps before any addition or subtraction steps, and
multiplication and division steps are processed left to right.

Additionally, the division that we use is floor division such that 10 * 9 /
8 equals 11.  This guarantees the result is an integer.

Implement the clumsy function as defined above: given an integer N, it returns the
clumsy factorial of N.

Note:
1 <= N <= 10000
-2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a 32-bit integer.)
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：4个num一组计算，再累加
*/
class Solution {
public:
	int clumsy(int N) {
		int res = 0;
		int count = 1, tmpRes = N;
		for (int num = N - 1; num >= 1; --num) {
			if (count % 4 == 0) {
				res += tmpRes;
				tmpRes = -1 * num;
				count = 0;
			} else if (count % 4 == 1)
				tmpRes *= num;
			else if (count % 4 == 2)
				tmpRes /= num;
			else if (count % 4 == 3)
				tmpRes += num;
			count++;
		}
		res += tmpRes;
		return res;
	}
};
int main() { return 0; }