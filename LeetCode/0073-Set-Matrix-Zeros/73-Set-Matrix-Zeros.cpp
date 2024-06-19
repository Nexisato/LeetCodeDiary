/*
LeetCode 73: Set Matrix Zeros
@Description:
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it
in-place.

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
*/
#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
思路：构造m条链表，第i条记录第i行矩阵中含0的列数
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<list<int>> table(m);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0)
					table[i].push_back(j);
			}
		}
		for (int i = 0; i < m; ++i) {
			bool flag = false;
			for (auto it = table[i].begin(); it != table[i].end(); ++it) {
				int col = *it;
				if (matrix[i][col] == 0) {
					for (int row = 0; row < m; row++)
						matrix[row][col] = 0;
					flag = true;
				}
			}
			if (flag)
				for (int j = 0; j < n; ++j)
					matrix[i][j] = 0;
		}
	}
};
/*
思路：使用标记数，将matrix[i][j]为0所在行列的边界设置为0
    for example：
        matrix[i][j] == 0;
        then matrix[[i][0] = 0, matrix[0][j] = 0;
    然后全盘扫描，当matrix[i][0] == 0 || matrix[0][j] == 0，设置matrix[i][j] = 0;
*/
class Solution_twoflags {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		bool flag_row0 = false, flag_col0 = false;
		for (int i = 0; i < m; ++i)
			if (matrix[i][0] == 0)
				flag_col0 = true;
		for (int j = 0; j < n; ++j)
			if (matrix[0][j] == 0)
				flag_row0 = true;
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
		if (flag_col0)
			for (int i = 0; i < m; ++i)
				matrix[i][0] = 0;
		if (flag_row0)
			for (int j = 0; j < n; ++j)
				matrix[0][j] = 0;
	}
};
int main() {
	Solution ss;
	vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
	int m = matrix.size(), n = matrix[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	ss.setZeroes(matrix);
	cout << "---After Set Zeros---" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}