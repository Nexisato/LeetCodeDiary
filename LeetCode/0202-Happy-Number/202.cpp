/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0202-Happy-Number/202.cpp
 * @Description:
 */
/*
LeetCode 202: Happy Number
@Description:
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
- Starting with any positive integer, replace the number by the sum of the squares of
its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.
- Return true if n is a happy number, and false if not.

Constraints:
1 <= n <= 2^31 - 1
*/
#include <iostream>
#include <unordered_set>
using namespace std;
/*
思路：
主要分为两种情况：
1. 是happyNum，最终变为1
2. 不断替换，进入循环
3. 增大到无穷大(不可能，以3位数举例，最大不会超过999，和为243，表明永远不会超过243，
即便是大于243的数，最终也会被困到243的循环内，因此不处理这种情况)
*/
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> appear;

		auto sum = [](int n) {
			int res = 0;
			while (n != 0) {
				int tmp = n % 10;
				res += tmp * tmp;
				n /= 10;
			}
			return res;
		};

		while (n != 1 && !appear.count(n)) {
			appear.insert(n);
			n = sum(n);
		}

		return n == 1;
	}
};
int main() { return 0; }