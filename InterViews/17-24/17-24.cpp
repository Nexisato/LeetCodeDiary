/*
LeetCode InterView 17.24: Max Submatrix LCCI
@Description:
Given an NxN matrix of positive and negative integers, write code to
find the submatrix with the largest possible sum.

Return an array [r1, c1, r2, c2], where r1, c1 are the row number and the column number
of the submatrix's upper left corner respectively, and r2, c2 are the row number of
and the column number of lower right corner. If there are more than one answers, return
any one of them.

Note: This problem is slightly different from the original one in the book.

Note:
1 <= matrix.length, matrix[0].length <= 200
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：

*/
// TODO
class Solution {
public:
	vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> sums(n + 1, vector<int>(m + 1));
		//区间和投影到边界
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				sums[j][i] = sums[j - 1][i - 1] + matrix[i - 1][j - 1];
		vector<int> res(4);
	}
};
int main() { return 0; }