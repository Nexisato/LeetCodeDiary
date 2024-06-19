/*
LeetCode 433: Sum of Square Numbers
@Description:
Given a non-negative integer c, decide whether there're two integers a and b such that
a^2 + b^2 = c.

Constraints:
0 <= c <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针
*/
class Solution {
public:
	bool judgeSquareSum(int c) {
		int maxSqrt = (int)sqrt(c);
		int a = 0;
		for (; a <= maxSqrt; ++a) {
			double b = sqrt(c - a * a);
			if (b == (int)b)
				return true;
		}
		return false;
	}
};
int main() {
	int c = 100000;
	Solution ss;
	bool tmp = ss.judgeSquareSum(c);
	cout << tmp << endl;

	return 0;
}