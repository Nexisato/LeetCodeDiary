/*
 * @Date: 2024-03-08 07:27:52
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/2834-Find-Minimum-Possible-Sum-of-Beautiful-Array/2834.cpp
 * @Description:
 */
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

/**
* 贪心地放入 1,2,3 ...
 注意括号括起来的位置，溢出很讲究
*/
class Solution {
public:
	int minimumPossibleSum(int n, int target) {
		const int modulo = 1e9 + 7;
		int mid = target / 2;
		if (mid >= n)
			return ((long long)n * (n + 1) / 2) % modulo;
		int d = n - mid;
		return ((long long)(mid + 1) * mid / 2 +
		        ((long long)target + target + d - 1) * d / 2) %
		       modulo;
	}
};
int main() { return 0; }