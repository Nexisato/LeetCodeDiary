/*
LeetCode 766: Toeplitz Matrix
@Description:

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same
elements.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99

Follow up:
What if the matrix is stored on disk, and the memory is limited such that you can only
load at most one row of the matrix into the memory at once? What if the matrix is so
large that you can only load up a partial row into the memory at once?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：从矩阵左侧与上侧开始模拟即可
*/
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m + n - 1; i++) {
			int row = (i > m - 1) ? 0 : i;
			int col = (i > m - 1) ? (i - m + 1) : 0;
			int num = matrix[row][col];
			while (row <= m && col <= n)
				if (matrix[row++][col++] != num)
					return false;
		}
		return true;
	}
};
int main() { return 0; }