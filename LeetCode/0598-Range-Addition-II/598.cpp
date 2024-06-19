/*
LeetCode 598: Range Addition
@Description:
You are given an m x n matrix M initialized with all 0's and an array of operations ops,
where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai
and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the
operations.

Constraints:
1 <= m, n <= 4 * 10^4
0 <= ops.length <= 10^4
ops[i].length == 2
1 <= ai <= m
1 <= bi <= n
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
思路：仅取左上角的最小交集即可
*/
class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int minR = m, minC = n;
		int opLength = ops.size();
		for (int i = 0; i < opLength; ++i) {
			minR = min(minR, ops[i][0]);
			minC = min(minC, ops[i][1]);
		}
		return minR * minC;
	}
};
int main() { return 0; }