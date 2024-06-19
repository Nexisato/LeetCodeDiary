/*
LeetCode 367: Valid Perfect Square
@Description:
Given a positive integer num, write a function which returns True if num is a perfect
square else False.

Follow up: Do not use any built-in library function such as sqrt.

Constraints:
1 <= num <= 2^31 - 1
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
思路：二分查找平方根
*/
class Solution {
public:
	bool isPerfectSquare(int num) {
		int l = 1, r = num;
		while (l <= r) {
			int mid = l + (r - l) >> 1;
			if ((long long)mid * mid > INT32_MAX)
				r = mid - 1;
			else {
				if (mid * mid < num)
					l = mid + 1;
				else if (mid * mid > num)
					r = mid - 1;
				else
					return true;
			}
		}
		return false;
	}
};
int main() {
	Solution* ss = new Solution();
	int num = 99;
	bool ans = ss->isPerfectSquare(num);

	return 0;
}